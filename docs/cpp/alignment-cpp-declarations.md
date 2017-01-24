---
title: "Alinhamento (declara&#231;&#245;es C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
ms.assetid: a986d510-ccb8-41f8-b905-433df9183485
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alinhamento (declara&#231;&#245;es C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um dos recursos de nível baixo do C\+\+ é a capacidade de especificar o alinhamento preciso de objetos na memória para tirar o máximo proveito de uma arquitetura de hardware específico.  Por padrão, o compilador alinha os membros de classe e estrutura em seu valor de tamanho: bool e char é alinhadas um dos limites de um byte, short em dois bytes, int em quatro bytes, long longos, double, long double em oito bytes.  Na maioria dos cenários, você nunca precisa se preocupar com alinhamento porque o alinhamento padrão já é ideal.  Em alguns casos, no entanto, você pode obter melhorias significativas no desempenho ou economias de memória, especificando um alinhamento personalizado para suas estruturas de dados.  Antes de 2015 do Visual Studio você pode usar o alignof de palavras\-chave específicas da Microsoft e declspec\(alignas\) para especificar um alinhamento maior que o padrão.  Iniciando no Visual Studio de 2015, você deve usar as C \+ \+ 11 palavras\-chave padrão [alignof e alignas](../cpp/alignof-and-alignas-cpp.md) para portabilidade de código máximo.  As novas palavras\-chave se comportam da mesma forma nos bastidores como as extensões específicas da Microsoft e a documentação para as extensões também se aplica às novas palavras\-chave.  Consulte [Operador \_\_alignof](../cpp/alignof-operator.md) e [align](../cpp/align-cpp.md) para obter mais informações.  O padrão C\+\+ não especificam o comportamento de empacotamento para alinhar em limites de menores do que o padrão do compilador para a plataforma de destino, portanto você ainda precisará usar o Microsoft \#pragma [pack](../preprocessor/pack.md) nesse caso.  
  
 O C\+\+ standard library fornece o [Classe aligned\_storage](../standard-library/aligned-storage-class.md) para alocar memória para as estruturas de dados com alinhamentos personalizados e o [Classe aligned\_union](../Topic/aligned_union%20Class.md) para especificar o alinhamento para uniões com incomum construtores ou destruidores.  
  
## Sobre o alinhamento  
 O alinhamento é uma propriedade de um endereço de memória, expressada como o endereço numérico de módulo uma potência de 2.  Por exemplo, o endereço 0x0001103F módulo 4 é 3; Esse endereço deve ser alinhado à 4n \+ 3, em que 4 indica escolhida potência de 2.  O alinhamento de um endereço depende da escolhido potência de dois.  O mesmo endereço módulo 8 é 7.  Um endereço deve ser alinhado a X se o alinhamento for Xn \+ 0.  
  
 CPUs executam instruções que operam nos dados armazenados na memória e os dados são identificados por seus endereços de memória.  Além de seu endereço, uma única referência também tem um tamanho.  Uma referência é chamada alinhada naturalmente se seu endereço é alinhado ao seu tamanho e desalinhados caso contrário.  Por exemplo, uma referência de ponto flutuante de 8 bytes é alinhada naturalmente se o endereço usado para identificá\-lo é alinhado para 8.  
  
 Tratamento de compilador de dados alignmentDevice compiladores tentar alocar dados de uma maneira que impede que o desalinhamento de dados.  
  
 Para tipos de dados simples, o compilador atribui endereços que são múltiplos de tamanho em bytes do tipo de dados.  Assim, o compilador atribui endereços a variáveis do tipo longo que são múltiplos de quatro, definindo os inferior dois bits do endereço como zero.  
  
 Além disso, o compilador acrescenta estruturas de forma que naturalmente se alinha cada elemento da estrutura.  Considere o x\_ de struct estrutura no exemplo de código a seguir:  
  
```  
struct x_  
{  
   char a;     // 1 byte  
   int b;      // 4 bytes  
   short c;    // 2 bytes  
   char d;     // 1 byte  
} MyStruct;  
  
```  
  
 O compilador preenche essa estrutura para impor o alinhamento naturalmente.  
  
 O exemplo de código a seguir mostra como o compilador coloca a estrutura preenchida na cópia de memória:  
  
```  
// Shows the actual memory layout  
struct x_  
{  
   char a;            // 1 byte  
   char _pad0[3];     // padding to put 'b' on 4-byte boundary  
   int b;            // 4 bytes  
   short c;          // 2 bytes  
   char d;           // 1 byte  
   char _pad1[1];    // padding to make sizeof(x_) multiple of 4  
}  
  
```  
  
1.  As duas declarações retornam sizeof\(struct x\_\) como 12 bytes.  
  
2.  A segunda declaração inclui dois elementos de preenchimento:  
  
3.  char \_pad0 \[3\] para alinhar o membro de b int em um limite de quatro bytes  
  
4.  char \_pad1 \[1\] para alinhar os elementos da matriz da estrutura de estrutura x barra \[3\];  
  
5.  O preenchimento alinha os elementos da barra \[3\], de forma que permita o acesso natural.  
  
 O exemplo de código a seguir mostra a barra de layout de matriz \[3\]:  
  
```  
adr offset   element  
------   -------  
0x0000   char a;         // bar[0]  
0x0001   char pad0[3];  
0x0004   int b;  
0x0008   short c;  
0x000a   char d;  
0x000b   char _pad1[1];  
  
0x000c   char a;         // bar[1]  
0x000d   char _pad0[3];  
0x0010   int b;  
0x0014   short c;  
0x0016   char d;  
0x0017   char _pad1[1];  
  
0x0018   char a;         // bar[2]  
0x0019   char _pad0[3];  
0x001c   int b;  
0x0020   short c;  
0x0022   char d;  
0x0023   char _pad1[1];  
  
```  
  
## Consulte também  
 [Alinhamento da estrutura de dados](http://en.wikipedia.org/wiki/Data_structure_alignment)