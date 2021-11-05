#include "parque.h"
#include <vector>

using namespace std;


ParqueEstacionamento::ParqueEstacionamento(unsigned lot, unsigned nMaxCli) : lotacao(lot), numMaximoClientes(nMaxCli){
    vagas = 0;
}

unsigned ParqueEstacionamento::getNumLugares() const {
    return lotacao;
}

unsigned ParqueEstacionamento::getNumMaximoClientes() const {
    return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const {
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes.at(i).nome == nome) {
            return i;
        }
    }
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome) {
    if (clientes.size() < numMaximoClientes) {
        InfoCartao cartao;
        cartao.nome = nome;
        cartao.presente = false;
        clientes.push_back(cartao);
        return true;
    }
    return false;
}

bool ParqueEstacionamento::entrar(const string & nome) {

    if (posicaoCliente(nome) == -1) {
        return false;
    }

    if (clientes.at(posicaoCliente(nome)).presente == true) {
        return false;
    }

    if (vagas >= lotacao) {
        return false;
    }

    vagas++;
    clientes.at(posicaoCliente(nome)).presente = true;
    return true;

}

bool ParqueEstacionamento::retiraCliente(const string & nome) {



    int index = posicaoCliente(nome);

    if (index == -1) {
        return false;
    }

    if (clientes.at(index).presente == true) {
        return false;
    }

    clientes.erase(clientes.begin() + index + 1);
    return true;
}

bool ParqueEstacionamento::sair(const string & nome) {

    int index = posicaoCliente(nome);

    if (index == -1) {
        return false;
    }

    if (clientes.at(index).presente == false) {
        return false;
    }

    clientes.at(index).presente = false;
    return true;

}

unsigned ParqueEstacionamento::getNumLugaresOcupados() const {
    return vagas;
}

unsigned ParqueEstacionamento::getNumClientesAtuais() const {
    return clientes.size();
}