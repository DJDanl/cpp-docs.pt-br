---
title: Constantes globais no C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- global constants
- constants, global
ms.assetid: df5a9bd4-d0a8-4c1c-956e-b481d0bded7d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1f1ee5fdf3d50f30e02bd48fe3664c10d26a8449
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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