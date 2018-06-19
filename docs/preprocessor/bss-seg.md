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
ms.openlocfilehash: 1b82027066e66cc51be8982a19ab6209ff236ef2
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33849802"
---
# <a name="bssseg"></a>bss_seg
Especifica o segmento em que as variáveis não inicializadas são armazenadas no arquivo .obj.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma bss_seg( [ [ { push | pop }, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )  
```  
  
## <a name="remarks"></a>Comentários  
 Arquivos obj podem ser exibidos com o [dumpbin](../build/reference/dumpbin-command-line.md) aplicativo. O segmento padrão no arquivo .obj para os dados não inicializados é .bss. Em alguns casos de uso de **bss_seg** pode acelerar tempos de carregamento por agrupamento de dados não inicializados em uma seção.  
  
 **bss_seg** sem parâmetros redefine o segmento para .bss.  
  
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
  
 Você também pode especificar seções de dados inicializado ([data_seg](../preprocessor/data-seg.md)), funções ([code_seg](../preprocessor/code-seg.md)) e as variáveis constantes ([const_seg](../preprocessor/const-seg.md)).  
  
 Dados alocados usando o **bss_seg** pragma não retém todas as informações sobre seu local.  
  
 Consulte [/seção](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ao criar uma seção.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)