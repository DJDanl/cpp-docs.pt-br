---
title: "Classe basic_fstream | Microsoft Docs"
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
  - "std::basic_fstream"
  - "basic_fstream"
  - "fstream/std::basic_fstream"
  - "std.basic_fstream"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe basic_fstream"
ms.assetid: 8473817e-42a4-430b-82b8-b476c86bcf8a
caps.latest.revision: 24
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe basic_fstream
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe[basic\_filebuf](../standard-library/basic-filebuf-class.md)\<`Elem``Tr`\>, com elementos do tipo`Elem`cujas características de caractere são determinadas pela classe`Tr`.  
  
## Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem> >  
    class basic_fstream : public basic_iostream<Elem, Tr>  
```  
  
#### Parâmetros  
 `Elem`  
 O elemento básico no buffer de arquivo.  
  
 `Tr`  
 Características do elemento básico no buffer de arquivo \(geralmente`char_traits`\<`Elem`\>\).  
  
## Comentários  
 O objeto armazena um objeto da classe`basic_filebuf`\<`Elem``Tr`\>.  
  
> [!NOTE]
>  O ponteiro de get e put ponteiro de um objeto fstream são**não**independentes umas das outras.  Se move o ponteiro de get, então não o ponteiro put.  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um`basic_fstream`objeto que pode ser lido de e gravado.  
  
```  
// basic_fstream_class.cpp  
// compile with: /EHsc  
  
#include <fstream>  
#include <iostream>  
  
using namespace std;  
  
int main(int argc, char **argv)  
{  
    fstream fs("fstream.txt", ios::in | ios::out | ios::trunc);  
    if (!fs.bad())  
    {  
        // Write to the file.  
        fs << "Writing to a basic_fstream object..." << endl;  
        fs.close();  
  
        // Dump the contents of the file to cout.  
        fs.open("fstream.txt", ios::in);  
        cout << fs.rdbuf();  
        fs.close();  
    }  
}  
```  
  
  **Gravando um objeto basic\_fstream...**   
### Construtores  
  
|||  
|-|-|  
|[basic\_fstream](../Topic/basic_fstream::basic_fstream.md)|Constrói um objeto do tipo`basic_fstream`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[close](../Topic/basic_fstream::close.md)|Fecha um arquivo.|  
|[is\_open](../Topic/basic_fstream::is_open.md)|Determina se um arquivo é aberto.|  
|[abrir](../Topic/basic_fstream::open.md)|Abre um arquivo.|  
|[rdbuf](../Topic/basic_fstream::rdbuf.md)|Retorna o endereço do buffer de fluxo armazenado do tipo ponteiro para[basic\_filebuf](../standard-library/basic-filebuf-class.md)\<`Elem``Tr`\>.|  
|[swap](../Topic/basic_fstream::swap.md)|Troca o conteúdo deste objeto com o conteúdo de outro`basic_fstream`objeto.|  
  
## Requisitos  
 **Cabeçalho:**\< fstream \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)