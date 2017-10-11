---
title: Erro fatal C1308 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1308
dev_langs:
- C++
helpviewer_keywords:
- C1308
ms.assetid: 46177997-069e-433a-8e20-93c846d78ffd
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: f9958ccb3daa537f8789d7485822fd623da8c703
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1308"></a>Erro fatal C1308
Não há suporte para vinculação assemblies  
  
 Um. netmodule é permitido como entrada para o vinculador, mas não é de um assembly. Esse erro pode ser gerado quando é feita uma tentativa para vincular um assembly compilado com `/clr:safe`.  
  
 Para obter mais informações, consulte [. netmodule arquivos como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).  
  
 O exemplo a seguir gera C1308:  
  
```  
// C1308.cpp  
// compile with: /clr:safe /LD  
public ref class MyClass {  
public:  
   int i;  
};  
```  
  
 E, em seguida,  
  
```  
// C1308b.cpp  
// compile with: /clr /link C1308b.obj C1308.dll  
// C1308 expected  
#using "C1308.dll"  
int main() {  
   MyClass ^ my = gcnew MyClass();  
}  
```
