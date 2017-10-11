---
title: alocar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- allocate_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], allocate
- allocate __declspec keyword
ms.assetid: 67828b31-de60-4c0e-b0a6-ef3aab22641d
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 4f61d3b6e6ab256262ea370516f20cdb76bf890e
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="allocate"></a>allocate
**Seção específica da Microsoft**  
  
 O **alocar** especificador de declaração nomeia um segmento de dados no qual o item de dados será alocado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
__declspec(allocate("  
segname  
")) declarator  
```  
  
## <a name="remarks"></a>Comentários  
 O nome *segname* devem ser declarados usando um dos pragmas a seguir:  
  
-   [code_seg](../preprocessor/code-seg.md)  
  
-   [const_seg](../preprocessor/const-seg.md)  
  
-   [data_seg](../preprocessor/data-seg.md)  
  
-   [init_seg](../preprocessor/init-seg.md)  
  
-   [seção](../preprocessor/section.md)  
  
## <a name="example"></a>Exemplo  
  
```  
// allocate.cpp  
#pragma section("mycode", read)  
__declspec(allocate("mycode"))  int i = 0;  
  
int main() {  
}  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
