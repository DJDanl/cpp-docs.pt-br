---
title: data_seg | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- data_seg_CPP
- vc-pragma.data_seg
dev_langs:
- C++
helpviewer_keywords:
- data_seg pragma
- pragmas, data_seg
ms.assetid: 65c66466-4c98-494f-93af-106beb4caf78
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9841b74d7bef74a117350b84747a606043d05d67
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707662"
---
# <a name="dataseg"></a>data_seg
Especifica o segmento de dados em que as variáveis inicializadas são armazenadas no arquivo .obj.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma data_seg( [ [ { push | pop }, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )  
```  
  
### <a name="parameters"></a>Parâmetros

**push**<br/>
(Opcional) Coloca um registro na pilha interna do compilador. Um **push** pode ter um *identificador* e *nome do segmento*.  

**pop**<br/>
(Opcional) Remove um registro do topo da pilha interna do compilador.  
  
*identifier*<br/>
(Opcional) Quando usado com **push**, atribui um nome ao registro na pilha interna do compilador. Quando usado com **pop-up**, elimina registros da pilha interna até *identificador* for removido; se *identificador* não for localizado na pilha interna, nada será exibido.  
  
*identificador* habilita vários registros a serem exibidos com uma única **pop-up** comando.  
  
*"nome do segmento"*<br/>
(Opcional) O nome de um segmento. Quando usado com **pop-up**, a pilha é exibida e *nome do segmento* se torna o nome do segmento ativo.  
  
*"segmento-class"*<br/>
(Opcional) Incluído para compatibilidade com o C++ antes da versão 2.0. É ignorado.  
  
## <a name="remarks"></a>Comentários 

O significado dos termos *segmento* e *seção* são usados alternadamente neste tópico.  
  
Arquivos OBJ podem ser exibidos com o [dumpbin](../build/reference/dumpbin-command-line.md) aplicativo. O segmento padrão no arquivo .obj para as variáveis inicializadas é .data. As variáveis que são não inicializadas são consideradas inicializadas em zero e são armazenadas em .bss.  
  
**data_seg** sem parâmetros redefine o segmento. Data.

## <a name="example"></a>Exemplo  
  
```cpp  
// pragma_directive_data_seg.cpp  
int h = 1;                     // stored in .data  
int i = 0;                     // stored in .bss  
#pragma data_seg(".my_data1")  
int j = 1;                     // stored in "my_data1"  
  
#pragma data_seg(push, stack1, ".my_data2")     
int l = 2;                     // stored in "my_data2"  
  
#pragma data_seg(pop, stack1)   // pop stack1 off the stack  
int m = 3;                     // stored in "stack_data1"  
  
int main() {  
}  
```  
  
Dados alocados usando **data_seg** não retêm nenhuma informação sobre o respectivo local.  
  
Ver [/seção](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ao criar uma seção.  
  
Você também pode especificar seções para variáveis const ([const_seg](../preprocessor/const-seg.md)), dados não inicializados ([bss_seg](../preprocessor/bss-seg.md)) e funções ([code_seg](../preprocessor/code-seg.md)).  
  
## <a name="see-also"></a>Consulte também  
 
[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)