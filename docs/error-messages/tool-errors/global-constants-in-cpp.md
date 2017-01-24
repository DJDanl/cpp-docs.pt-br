---
title: "Constantes globais no C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "constantes, global"
  - "constantes globais"
ms.assetid: df5a9bd4-d0a8-4c1c-956e-b481d0bded7d
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes globais no C++
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As constantes globais C\+\+ têm vinculação estática.  Isso é diferente de 2.0 C.  Se você tentar usar uma constante global em C\+\+ em vários arquivos você receber um erro externo não resolvido.  O compilador otimiza constantes globais para fora do, não deixando nenhum espaço reservado para a variável.  
  
 Uma forma de resolver esse erro é incluir as inicializações de const em um arquivo de cabeçalho e incluir esse cabeçalho nos arquivos de CPP quando necessário, como se fosse protótipo da função.  Outra possibilidade é fazer a variável não constante e usar uma referência constante para avaliá\-la.  
  
 O seguinte exemplo gera C2019:  
  
```  
// global_constants.cpp  
// LNK2019 expected  
void test(void);  
const int lnktest1 = 0;  
  
int main() {  
   test();  
}  
```  
  
 Em seguida, e  
  
```  
// global_constants_2.cpp  
// compile with: global_constants.cpp  
extern int lnktest1;  
  
void test() {  
  int i = lnktest1;   // LNK2019  
}  
```  
  
## Consulte também  
 [Erro das Ferramentas de Vinculador LNK2019](../Topic/Linker%20Tools%20Error%20LNK2019.md)