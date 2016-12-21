---
title: "C4868 de aviso do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4868"
ms.assetid: fc6aa7e5-34dd-4ec2-88bd-16e430361dc7
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C4868 de aviso do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

compilador 'file\(line\_number\)' não pode impor a ordem de avaliação da esquerda para a direita na lista de inicializadores entre chaves  
  
 Os elementos de uma lista de inicializadores entre chaves devem ser avaliados em ordem da esquerda para a direita. Há dois casos em que o compilador é capaz de garantir nesta ordem: a primeira é quando alguns dos elementos são objetos passados por valor. a segunda é durante a compilação com `/clr` e alguns dos elementos são campos de objetos ou elementos de matriz. Quando o compilador não pode garantir a avaliação da esquerda para a direita emite aviso C4868.  
  
 Esse aviso pode ser gerado como resultado de trabalho de conformidade do compilador que foi feito para a atualização 2 do Visual C\+\+ 2015. Código compilado antes da atualização 2 do Visual C\+\+ 2015 agora irá gerar C4868.  
  
 Esse aviso é desativada por padrão. Use `/parede` para ativar esse aviso.  
  
 Para resolver esse aviso, considere se a avaliação da esquerda para a direita dos elementos de lista de inicializador é necessária, como quando a avaliação dos elementos pode produzir efeitos colaterais depende da ordem. Em muitos casos, a ordem na qual os elementos são avaliados não tem um efeito observável.  
  
 Se a ordem de avaliação deve ser esquerda para direita, considere se é possível passar em vez disso, os elementos por referência \(const\). Uma alteração como isso elimina o aviso no exemplo de código a seguir.  
  
## Exemplo  
 O exemplo a seguir gera C4868.  
  
```  
// C4868.cpp  
// compile with: /c /Wall  
#include <cstdio>  
  
class HasCopyConstructor  
{  
public:  
    int x;  
  
    HasCopyConstructor(int x): x(x) {}  
  
    HasCopyConstructor(const HasCopyConstructor& h): x(h.x)  
    {  
        printf("Constructing %d\n", h.x);  
    }  
};  
  
class TripWarning4868  
{  
public:  
    // note that taking "HasCopyConstructor" parameters by-value will trigger copy-construction.  
    TripWarning4868(HasCopyConstructor a, HasCopyConstructor b) {}  
  
    // This variation will not trigger the warning:  
    // TripWarning4868(const HasCopyConstructor& a, const HasCopyConstructor& b) {}  
};  
  
int main()  
{  
    HasCopyConstructor a{1};  
    HasCopyConstructor b{2};  
  
    // the warning will indicate the below line, the usage of the braced initializer list.  
    TripWarning4868 warningOnThisLine{a, b};  
};  
```