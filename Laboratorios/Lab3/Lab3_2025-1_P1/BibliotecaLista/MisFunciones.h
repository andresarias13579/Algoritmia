//
// Created by aml on 15/05/2026.
//

#ifndef LISTASIMPLEMENTEENLAZADA_MISFUNCIONES_H
#define LISTASIMPLEMENTEENLAZADA_MISFUNCIONES_H

void insertarDatos(const char* codigo,const char *nombre,int ventas,int likes,struct ElementoLista &elemento);
void ordenarLista(struct Lista &listaLibros);
void cambiarNodos(struct Lista &listaLibros,int n,int k);
void buscarIndicesVentas(struct Lista listaLibros,int &n,int &k);
void buscarIndicesLikes(struct Lista listaLibros,int &n,int &k);

#endif //LISTASIMPLEMENTEENLAZADA_MISFUNCIONES_H