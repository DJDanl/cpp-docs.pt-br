---
title: "Elaborando os seus pr&#243;prios manipuladores sem argumentos | Microsoft Docs"
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
helpviewer_keywords: 
  - "manipuladores"
ms.assetid: 2dc62d09-45b7-454d-bd9d-55f3c72c206d
caps.latest.revision: 8
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Elaborando os seus pr&#243;prios manipuladores sem argumentos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os manipuladores de gravação que não usam argumentos requerem nem a derivação da classe ou o uso de macros complexos.  Suponha que sua impressora exige os pares \<\[ESC\>para entrar no modo em negrito.  Você pode inserir esse par diretamente no fluxo:  
  
```  
cout << "regular " << '\033' << '[' << "boldface" << endl;  
```  
  
 Ou você pode definir o manipulador de `bold` , que insere os caracteres:  
  
```  
ostream& bold( ostream& os ) {  
    return os << '\033' << '[';  
}  
cout << "regular " << bold << "boldface" << endl;  
```  
  
 A função global definida de `bold` usa um argumento de referência de `ostream` e retorna a referência de `ostream` .  Não é uma função de membro ou um amigo porque não precisa de acesso aos elementos privados da classe.  A função de `bold` se conecta ao fluxo porque o operador de `<<` de fluxo é sobrecarregado para aceitar esse tipo de função, usando uma instrução que inspeciona aparência:  
  
```  
_Myt& operator<<(ios_base& (__cdecl *_Pfn)(ios_base&))  
{     
   // call ios_base manipulator  
   (*_Pfn)(*(ios_base *)this);  
   return (*this);  
}  
```  
  
 Você pode usar esse recurso para estender outros operadores sobrecarregados.  Nesse caso, é incidental que `bold` insere caracteres no fluxo.  A função é chamada quando é inserida no fluxo, não necessariamente quando os caracteres adjacentes são impressos.  Assim, imprimir pode ser atrasado devido à proteção de fluxo.  
  
## Consulte também  
 [Fluxos de Saída](../standard-library/output-streams.md)