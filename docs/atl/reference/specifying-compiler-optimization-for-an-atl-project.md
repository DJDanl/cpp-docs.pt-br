---
title: "Especificando otimiza&#231;&#227;o de compilador para um projeto ATL | Microsoft Docs"
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
  - "vc.appwiz.ATL.optimization"
  - "vc.appwiz.ATL.vtable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "projetos ATL, otimização do compilador"
  - "macro ATL_DISABLE_NO_VTABLE"
  - "macro ATL_NO_VTABLE"
ms.assetid: 7f379318-66d5-43dd-a53d-530758d3a228
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificando otimiza&#231;&#227;o de compilador para um projeto ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Por padrão, [Assistente de controle de ATL](../../atl/reference/atl-control-wizard.md) gera novas classes com a macro de ATL\_NO\_VTABLE, como segue:  
  
```  
class ATL_NO_VTABLE CProjName  
{  
   ...  
};  
```  
  
 ATL então define o \_ATL\_NO\_VTABLE como segue:  
  
```  
#ifdef _ATL_DISABLE_NO_VTABLE  
   #define ATL_NO_VTABLE  
#else  
   #define ATL_NO_VTABLE __declspec(novtable)  
#endif  
```  
  
 Se você não definir o \_ATL\_DISABLE\_NO\_VTABLE, a macro de ATL\_NO\_VTABLE expande para `declspec(novtable)`.  Usar `declspec(novtable)`em uma declaração de classe impede que o ponteiro vtable é inicializado no construtor e o destrutor da classe.  Quando você compila seu projeto, o vinculador vtable e elimina todas as funções para que os pontos vtable.  
  
 Você deve usar ATL\_NO\_VTABLE e, portanto `declspec(novtable)`, com apenas classes base que não são diretamente creatable.  Você não deve usar `declspec(novtable)` com a classe mais derivada, em seu projeto como essa classe \(geralmente [CComObject](../../atl/reference/ccomobject-class.md)[CComAggObject](../../atl/reference/ccomaggobject-class.md), ou\) [CComPolyObject](../../atl/reference/ccompolyobject-class.md)inicializa o ponteiro vtable para seu projeto.  
  
 Você não deve chamar funções virtuais de construtor de qualquer objeto que usar `declspec(novtable)`.  Você deve mover esses chamadas para o método de [FinalConstruct](../Topic/CComObjectRootEx::FinalConstruct.md) .  
  
 Se você não tiver certeza se você deve usar o modificador de `declspec(novtable)` , você pode remover a macro de ATL\_NO\_VTABLE de qualquer definição de classe, ou você pode desativá\-lo especificando global  
  
```  
#define _ATL_DISABLE_NO_VTABLE  
```  
  
 em stdafx.h, antes de quaisquer arquivos de cabeçalho restantes de ATL é incluído.  
  
## Consulte também  
 [Assistente de Projeto ATL](../Topic/ATL%20Project%20Wizard.md)   
 [Tipos de projeto do Visual C\+\+](../../ide/visual-cpp-project-types.md)   
 [Criando projetos para desktop com Assistentes de Aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Programando com código de tempo de execução ATL e C](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Fundamentos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [novtable](../../cpp/novtable.md)   
 [Configurações padrão do projeto ATL](../../atl/reference/default-atl-project-configurations.md)