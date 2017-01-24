---
title: "Classe de _U_STRINGorID | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL._U_STRINGorID"
  - "ATL::_U_STRINGorID"
  - "_U_STRINGorID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de _U_STRINGorID"
  - "Classe de U_STRINGorID"
ms.assetid: 443cdc00-d265-4b27-8ef3-2feb95f3e5e3
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de _U_STRINGorID
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe do adaptador do argumento permite nomes de recurso \(`LPCTSTR`s\) ou IDs de recurso \(**UINT**s\) a serem passados para uma função sem exigir o chamador converter a identificação a uma cadeia de caracteres usando a macro de **MAKEINTRESOURCE** .  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class _U_STRINGorID  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[\_U\_STRINGorID::\_U\_STRINGorID](../Topic/_U_STRINGorID::_U_STRINGorID.md)|o construtor.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[\_U\_STRINGorID::m\_lpstr](../Topic/_U_STRINGorID::m_lpstr.md)|O identificador do recurso.|  
  
## Comentários  
 Essa classe é criada implementando wrappers para o gerenciamento de recursos API do windows como as funções de [FindResource](http://msdn.microsoft.com/library/windows/desktop/ms648042), de [LoadIcon](http://msdn.microsoft.com/library/windows/desktop/ms648072), e de [LoadMenu](http://msdn.microsoft.com/library/windows/desktop/ms647990) , que aceita um argumento de `LPCTSTR` que pode ser o nome de um recurso ou sua identificação  
  
 A classe define duas sobrecargas de construtor: se aceita um argumento de `LPCTSTR` e o outro aceita um argumento de **UINT** .  O argumento de **UINT** é convertido para um tipo de recurso compatível com funções do recurso de gerenciamento do windows usando a macro de **MAKEINTRESOURCE** e o resultado armazenados membro de dados da classe no único, [m\_lpstr](../Topic/_U_STRINGorID::m_lpstr.md).  O argumento para o construtor de `LPCTSTR` é armazenado diretamente sem conversão.  
  
## Requisitos  
 **Cabeçalho:** atlwin.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)