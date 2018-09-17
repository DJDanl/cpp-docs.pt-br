---
title: bss_seg | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- vc-pragma.bss_seg
- bss_seg_CPP
dev_langs:
- C++
helpviewer_keywords:
- pragmas, bss_seg
- bss_seg pragma
ms.assetid: 755f0154-de51-4778-97d3-c9b24e445079
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3c3a80e50bd0b012773a5e5a197674965f73b526
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45711146"
---
# <a name="bssseg"></a>bss_seg
Especifica o segmento em que as variáveis não inicializadas são armazenadas no arquivo .obj.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma bss_seg( [ [ { push | pop }, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )  
```  
  
## <a name="remarks"></a>Comentários  

Arquivos obj podem ser exibidos com o [dumpbin](../build/reference/dumpbin-command-line.md) aplicativo. O segmento padrão no arquivo .obj para os dados não inicializados é .bss. Em alguns casos de uso de **bss_seg** pode acelerar tempos de carregamento, agrupando dados não inicializados em uma seção.  
  
**bss_seg** sem parâmetros redefine o segmento BSS.  
  
**push**<br/>
(Opcional) Coloca um registro na pilha interna do compilador. Um *pu*sh * pode ter um *identificador* e *nome do segmento*.  
  
**pop**<br/>
(Opcional) Remove um registro do topo da pilha interna do compilador.  
  
*identifier*<br/>
(Opcional) Quando usado com **push**, atribui um nome ao registro na pilha interna do compilador. Quando usado com **pop-up**, elimina registros da pilha interna até *identificador* for removido; se *identificador* não for localizado na pilha interna, nada será exibido.  
  
*identificador* habilita vários registros a serem exibidos com uma única **pop-up** comando.  
  
*"nome do segmento"*<br/>
(Opcional) O nome de um segmento. Quando usado com **pop-up**, a pilha é exibida e *nome do segmento* se torna o nome do segmento ativo.  
  
*"segmento-class"*<br/>
(Opcional) Incluído para compatibilidade com o C++ antes da versão 2.0. É ignorado.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// pragma_directive_bss_seg.cpp  
int i;                     // stored in .bss  
#pragma bss_seg(".my_data1")  
int j;                     // stored in "my_data1"  
  
#pragma bss_seg(push, stack1, ".my_data2")     
int l;                     // stored in "my_data2"  
  
#pragma bss_seg(pop, stack1)   // pop stack1 from stack  
int m;                     // stored in "stack_data1"  
  
int main() {  
}  
```  
  
Você também pode especificar seções para dados inicializados ([data_seg](../preprocessor/data-seg.md)), funções ([code_seg](../preprocessor/code-seg.md)) e variáveis constantes ([const_seg](../preprocessor/const-seg.md)).  
  
Dados alocados usando o **bss_seg** pragma não retêm nenhuma informação sobre o respectivo local.  
  
Ver [/seção](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ao criar uma seção.  
  
## <a name="see-also"></a>Consulte também  
 
[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)