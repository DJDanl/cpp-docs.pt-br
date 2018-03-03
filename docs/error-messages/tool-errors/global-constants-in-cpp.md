---
title: Constantes globais no C++ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- global constants
- constants, global
ms.assetid: df5a9bd4-d0a8-4c1c-956e-b481d0bded7d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 766e1a6f48ecf3f64110e64d916c50d92c89345d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="global-constants-in-c"></a>Constantes globais no C++
Constantes globais C++ tem vinculação estática. Isso é diferente de C. Se tentar usar um global constante em C++ em vários arquivos você receberá um erro externo não resolvido. O compilador otimiza constantes globais, não deixando nenhum espaço reservado para a variável.  
  
 É uma maneira de resolver esse erro incluem as inicializações constantes em um arquivo de cabeçalho e inclua esse cabeçalho nos arquivos CPP quando necessário, como se fosse o protótipo de função. Outra possibilidade é a variável não constante e usar uma referência constante ao avaliar a ele.  
  
 O exemplo a seguir gera C2019:  
  
```  
// global_constants.cpp  
// LNK2019 expected  
void test(void);  
const int lnktest1 = 0;  
  
int main() {  
   test();  
}  
```  
  
 E, em seguida,  
  
```  
// global_constants_2.cpp  
// compile with: global_constants.cpp  
extern int lnktest1;  
  
void test() {  
  int i = lnktest1;   // LNK2019  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Erro das ferramentas de vinculador LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md)