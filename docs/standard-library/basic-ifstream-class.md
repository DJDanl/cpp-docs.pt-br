---
title: "Classe basic_ifstream | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "basic_ifstream"
  - "fstream/std::basic_ifstream"
  - "std::basic_ifstream"
  - "std.basic_ifstream"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe basic_ifstream"
ms.assetid: 366cd9a7-efc4-4b7f-ba10-c8271e47ffcf
caps.latest.revision: 23
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe basic_ifstream
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe[basic\_filebuf](../standard-library/basic-filebuf-class.md)\<`Elem``Tr`\>, com elementos do tipo`Elem`cujas características de caractere são determinadas pela classe`Tr`.  
  
## Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem> >  
    class basic_ifstream : public basic_istream<Elem, Tr>  
```  
  
#### Parâmetros  
 `Elem`  
 O elemento básico no buffer de arquivo.  
  
 `Tr`  
 Características do elemento básico no buffer de arquivo \(geralmente`char_traits`\<`Elem`\>\).  
  
## Comentários  
 O objeto armazena um objeto da classe`basic_filebuf`\<`Elem``Tr`\>.  
  
## Exemplo  
 O exemplo a seguir mostra como ler texto de um arquivo.  
  
```  
// basic_ifstream_class.cpp  
// compile with: /EHsc  
  
#include <fstream>  
#include <iostream>  
  
using namespace std;  
  
int main(int argc, char **argv)  
{  
    ifstream ifs("basic_ifstream_class.txt");  
    if (!ifs.bad())  
    {  
        // Dump the contents of the file to cout.  
        cout << ifs.rdbuf();  
        ifs.close();  
    }  
}  
```  
  
## Entrada: basic\_ifstream\_class.txt  
  
```  
This is the contents of basic_ifstream_class.txt.  
```  
  
## Saída  
  
```  
This is the contents of basic_ifstream_class.txt.  
```  
  
### Construtores  
  
|||  
|-|-|  
|[basic\_ifstream](../Topic/basic_ifstream::basic_ifstream.md)|Inicializa uma nova instância de um`basic_ifstream`objeto.|  
  
### Funções membro  
  
|||  
|-|-|  
|[close](../Topic/basic_ifstream::close.md)|Fecha um arquivo.|  
|[is\_open](../Topic/basic_ifstream::is_open.md)|Determina se um arquivo é aberto.|  
|[abrir](../Topic/basic_ifstream::open.md)|Abre um arquivo.|  
|[rdbuf](../Topic/basic_ifstream::rdbuf.md)|Retorna o endereço do buffer de fluxo armazenado.|  
|[swap](../Topic/basic_ifstream::swap.md)|Troca o conteúdo dessa`basic_ifstream`para o conteúdo fornecido`basic_ifstream`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=](../Topic/basic_ifstream::operator=.md)|Atribui o conteúdo deste objeto de fluxo.  Isso é uma atribuição de movimentação que envolvem um`rvalue`que não deixar uma cópia.|  
  
## Requisitos  
 **Cabeçalho:**\< fstream \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)