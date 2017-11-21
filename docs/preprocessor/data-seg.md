---
title: data_seg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- data_seg_CPP
- vc-pragma.data_seg
dev_langs: C++
helpviewer_keywords:
- data_seg pragma
- pragmas, data_seg
ms.assetid: 65c66466-4c98-494f-93af-106beb4caf78
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 5fa88a9c2afaff7d9e2e4c6aca4baa4af2a17833
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="dataseg"></a>data_seg
Especifica o segmento de dados em que as variáveis inicializadas são armazenadas no arquivo .obj.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma data_seg( [ [ { push | pop }, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )  
```  
  
## <a name="remarks"></a>Comentários  
 O significado dos termos de *segmento* e *seção* são intercambiáveis neste tópico.  
  
 Arquivos OBJ podem ser exibidos com o [dumpbin](../build/reference/dumpbin-command-line.md) aplicativo. O segmento padrão no arquivo .obj para as variáveis inicializadas é .data. As variáveis que são não inicializadas são consideradas inicializadas em zero e são armazenadas em .bss.  
  
 **data_seg** sem parâmetros redefine o segmento para. Data.  
  
 **push**(opcional)  
 Coloca um registro na pilha interna do compilador. Um **push** pode ter um *identificador* e *nome de segmento*.  
  
 **pop** (opcional)  
 Remove um registro do topo da pilha interna do compilador.  
  
 *identificador* (opcional)  
 Quando usado com **push**, atribui um nome para o registro na pilha do compilador interno. Quando usado com **pop**, pops registros na pilha interna até *identificador* for removido; se *identificador* não foi encontrado na pilha interna, nada é exibido.  
  
 *identificador* permite que vários registros deve ser exibido com um único **pop** comando.  
  
 *"nome do segmento"*(opcional)  
 O nome de um segmento. Quando usado com **pop**, a pilha é exibida e *nome de segmento* se torna o nome de segmento ativo.  
  
 *"classe de segmento"* (opcional)  
 Incluído para compatibilidade com o C++ antes da versão 2.0. É ignorado.  
  
## <a name="example"></a>Exemplo  
  
```  
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
  
 Dados alocados usando **data_seg** não retém todas as informações sobre seu local.  
  
 Consulte [/seção](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ao criar uma seção.  
  
 Você também pode especificar seções para variáveis constantes ([const_seg](../preprocessor/const-seg.md)), dados foi cancelada ([bss_seg](../preprocessor/bss-seg.md)) e funções ([code_seg](../preprocessor/code-seg.md)).  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)