---
title: Alinhamento (declarações C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: a986d510-ccb8-41f8-b905-433df9183485
caps.latest.revision: 4
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 019884793eb3472e52c7772351b2f5826520a193
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="alignment-c-declarations"></a>Alinhamento (declarações C++)
Um dos recursos de nível inferior do C++ é a capacidade de especificar o alinhamento preciso de objetos na memória para tirar o máximo proveito de uma arquitetura de hardware específico. Por padrão, o compilador alinha os membros de classe e struct em seu valor de tamanho: bool e char está alinhados um limites de um byte, short em dois bytes, int em quatro bytes, long longos, double, long double oito bytes. Na maioria dos cenários, você nunca precisa se preocupar com alinhamento porque o alinhamento padrão já é ideal. Em alguns casos, no entanto, você pode obter melhorias significativas de desempenho ou economia de memória, especificando um alinhamento personalizado para suas estruturas de dados. Antes do Visual Studio 2015, você pode usar o alignof de palavras-chave específicas da Microsoft e declspec(alignas) para especificar um alinhamento maior do que o padrão. Iniciando no Visual Studio 2015, você deve usar as C++ 11 palavras-chave padrão [alignof e alignas](../cpp/alignof-and-alignas-cpp.md) para a portabilidade de código máximo. As novas palavras-chave se comportam da mesma forma nos bastidores, como as extensões específicas da Microsoft e a documentação para as extensões também se aplica às novas palavras-chave. Consulte [alignof operador](../cpp/alignof-operator.md) e [alinhar](../cpp/align-cpp.md) para obter mais informações. O padrão C++ não especificar o comportamento de empacotamento de alinhamento em limites de menores do que o padrão do compilador para a plataforma de destino, para que você ainda precisa usar o Microsoft #pragma [pacote](../preprocessor/pack.md) nesse caso.  
  
 A biblioteca padrão C++ fornece o [classe aligned_storage](../standard-library/aligned-storage-class.md) para alocar memória para estruturas de dados com alinhamentos personalizados e o [classe aligned_union](../standard-library/aligned-union-class.md) para especificar o alinhamento de uniões com não trivial construtores ou destrutores.  
  
## <a name="about-alignment"></a>Sobre o alinhamento  
 Alinhamento é uma propriedade de um endereço de memória, expressada como o endereço numérico módulo uma potência de 2. Por exemplo, o endereço 0x0001103F módulo 4 é 3; Esse endereço deve ser alinhado a 4n + 3, onde 4 indica escolhida potência de 2. O alinhamento de um endereço depende a escolhido potência de dois. O mesmo endereço módulo 8 é 7. Um endereço deve ser alinhado a X se seu alinhamento é Xn + 0.  
  
 CPUs executam instruções que operam nos dados armazenados na memória e os dados são identificados por seus endereços de memória. Além de seu endereço, uma única referência também tem um tamanho. Uma referência é chamada naturalmente alinhada se seu endereço é alinhado ao seu tamanho e desalinhados caso contrário. Por exemplo, uma referência de ponto flutuante de 8 bytes naturalmente é alinhada se o endereço usado para identificá-lo é alinhado em 8.  
  
 Tratamento de compilador de dados alignmentDevice compiladores tentar alocar dados de uma maneira que impede que o desalinhamento de dados.  
  
 Para tipos de dados simples, o compilador atribui endereços que sejam múltiplos de tamanho em bytes do tipo de dados. Assim, o compilador atribui endereços para variáveis do tipo longo que sejam múltiplos de quatro, definindo os parte inferior dois bits do endereço a zero.  
  
 Além disso, o compilador preenche estruturas de forma que naturalmente Alinha cada elemento da estrutura. Considere o x_ da estrutura de estrutura no exemplo de código a seguir:  
  
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
  
1.  As duas declarações de retorno sizeof(struct x_) como 12 bytes.  
  
2.  A segunda declaração inclui dois elementos de preenchimento:  
  
3.  char _pad0 [3] para alinhar o membro de b int em um limite de quatro bytes  
  
4.  char _pad1 [1] para alinhar os elementos da matriz da estrutura de estrutura x barra [3];  
  
5.  O preenchimento alinha os elementos da barra [3], de forma que permita o acesso natural.  
  
 O exemplo de código a seguir mostra a barra de layout de matriz [3]:  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Alinhamento da estrutura de dados](http://en.wikipedia.org/wiki/Data_structure_alignment)