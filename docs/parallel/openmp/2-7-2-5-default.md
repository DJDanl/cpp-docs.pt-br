---
title: "2.7.2.5 default | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: c856df07-705c-4ad3-9105-a268dd33e939
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.7.2.5 default
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **padrão** cláusula permite que o usuário afetam os atributos de compartilhamento de dados de variáveis.  A sintaxe do  **padrão** cláusula é da seguinte maneira:  
  
```  
default(shared | none)  
```  
  
 Especificando  **default\(shared\)** é equivalente a explicitamente listando cada variável visível no momento em um  **compartilhado** cláusula, a menos que ele seja  **threadprivate** ou  **contras**`t`\-qualificado.  Na ausência de um explícita  **padrão** cláusula, o comportamento padrão é o mesmo que se  **default\(shared\)** foram especificados.  
  
 Especificando  **default\(none\)** requer que pelo menos um dos seguintes deve ser verdadeiro para cada referência a uma variável na extensão lexical da construção paralela:  
  
-   A variável é explicitamente listada em uma cláusula de atributo de compartilhamento de dados de uma construção que contém a referência.  
  
-   A variável é declarada dentro a construção parallel.  
  
-   A variável é  **threadprivate**.  
  
-   A variável tem um  **const**\-qualificado do tipo.  
  
-   A variável é a variável de controle de loop para uma  **para** loop que segue imediatamente um  **para** ou  **paralela para** diretiva e a referência da variável é exibido dentro do loop.  
  
 Especifica uma variável em um  **firstprivate**,  **lastprivate**, ou  **redução** cláusula de uma diretiva incluso faz com que uma referência à variável implícita no contexto de delimitador.  Tais referências implícitas também estão sujeitos aos requisitos listados acima.  
  
 Um único  **padrão** cláusula pode ser especificada em um  **paralela** diretiva.  
  
 Padrão de uma variável atributo de compartilhamento de dados pode ser sobrescrito, usando o  **particular**,  **firstprivate**,  **lastprivate**,  **redução de**, e  **compartilhado** cláusulas, como demonstrado pelo exemplo a seguir:  
  
```  
#pragma  omp  parallel  for  default(shared)  firstprivate(i)\  
   private(x)  private(r)  lastprivate(i)  
```