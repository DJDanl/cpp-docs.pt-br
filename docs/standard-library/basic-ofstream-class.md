---
title: "Classe basic_ofstream | Microsoft Docs"
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
  - "std::basic_ofstream"
  - "basic_ofstream"
  - "std.basic_ofstream"
  - "fstream/std::basic_ofstream"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe basic_ofstream"
ms.assetid: 3bcc9c51-6dfc-4844-8fcc-22ef57c9dff1
caps.latest.revision: 24
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe basic_ofstream
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo da classe[basic\_filebuf](../standard-library/basic-filebuf-class.md)\<`Elem``Tr`\>, com elementos do tipo`Elem`cujas características de caractere são determinadas pela classe`Tr`.  
  
## Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem> >  
    class basic_ofstream : public basic_ostream<Elem, Tr>  
```  
  
#### Parâmetros  
 `Elem`  
 O elemento básico no buffer de arquivo.  
  
 `Tr`  
 Características do elemento básico no buffer de arquivo \(geralmente`char_traits`\<`Elem`\>\).  
  
## Comentários  
 Quando o`wchar_t`especialização de`basic_ofstream`grava no arquivo, se o arquivo é aberto no modo de texto, ele gravará uma sequência MBCS.  A representação interna usará um buffer de`wchar_t`caracteres.  
  
 O objeto armazena um objeto da classe`basic_filebuf`\<`Elem``Tr`\>.  
  
## Exemplo  
 O exemplo a seguir mostra como criar um`basic_ofstream`do objeto e escrever texto a ele.  
  
```  
// basic_ofstream_class.cpp  
// compile with: /EHsc  
#include <fstream>  
  
using namespace std;  
  
int main(int argc, char **argv)  
{  
    ofstream ofs("ofstream.txt");  
    if (!ofs.bad())  
    {  
        ofs << "Writing to a basic_ofstream object..." << endl;  
        ofs.close();  
    }  
}  
```  
  
### Construtores  
  
|||  
|-|-|  
|[basic\_ofstream](../Topic/basic_ofstream::basic_ofstream.md)|Cria um objeto do tipo`basic_ofstream`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[close](../Topic/basic_ofstream::close.md)|Fecha um arquivo.|  
|[is\_open](../Topic/basic_ofstream::is_open.md)|Determina se um arquivo é aberto.|  
|[abrir](../Topic/basic_ofstream::open.md)|Abre um arquivo.|  
|[rdbuf](../Topic/basic_ofstream::rdbuf.md)|Retorna o endereço do buffer de fluxo armazenado.|  
|[swap](../Topic/basic_ofstream::swap.md)|O conteúdo do Exchange`basic_ofstream`para o conteúdo fornecido`basic_ofstream`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=](../Topic/basic_ofstream::operator=.md)|Atribui o conteúdo deste objeto de fluxo.  Isso é uma atribuição de movimentação que envolvem um`rvalue reference`que não deixar uma cópia.|  
  
## Requisitos  
 **Cabeçalho:**\< fstream \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Classe basic\_ostream](../Topic/basic_ostream%20Class.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)