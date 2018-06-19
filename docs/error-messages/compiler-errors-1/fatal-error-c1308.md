---
title: Erro fatal C1308 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1308
dev_langs:
- C++
helpviewer_keywords:
- C1308
ms.assetid: 46177997-069e-433a-8e20-93c846d78ffd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dca537131f111c02dd642dff869510eca788b9a7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33226839"
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