---
title: "Classe de CWndClassInfo | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CWndClassInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CWndClassInfo"
ms.assetid: c36fe7e1-75f1-4cf5-a06f-9f59c43fe6fb
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWndClassInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para registrar informações de uma classe de janela.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CWndClassInfo  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|||  
|-|-|  
|[Registro](../Topic/CWndClassInfo::Register.md)|Registra a classe de janela.|  
  
### Membros de dados  
  
|||  
|-|-|  
|[m\_atom](../Topic/CWndClassInfo::m_atom.md)|Identifica a classe registrada da janela.|  
|[m\_bSystemCursor](../Topic/CWndClassInfo::m_bSystemCursor.md)|Especifica se o recurso do cursor se refere a um cursor do sistema ou cursor contido em um recurso de módulo.|  
|[m\_lpszCursorID](../Topic/CWndClassInfo::m_lpszCursorID.md)|Especifica o nome de recurso do cursor.|  
|[m\_lpszOrigName](../Topic/CWndClassInfo::m_lpszOrigName.md)|Contém o nome de uma classe existente da janela.|  
|[m\_szAutoName](../Topic/CWndClassInfo::m_szAutoName.md)|Contém um nome ATL\- gerado de classe da janela.|  
|[m\_wc](../Topic/CWndClassInfo::m_wc.md)|Mantém informações da classe da janela em uma estrutura de **WNDCLASSEX** .|  
|[pWndProc](../Topic/CWndClassInfo::pWndProc.md)|Os pontos ao procedimento de janela de uma janela classe existente.|  
  
## Comentários  
 `CWndClassInfo` gerencia informações de uma classe de janela.  Você normalmente usa `CWndClassInfo` com um dos três macros, `DECLARE_WND_CLASS`, `DECLARE_WND_CLASS_EX`, ou `DECLARE_WND_SUPERCLASS`, conforme descrito na tabela a seguir:  
  
|Macro|Descrição|  
|-----------|---------------|  
|[DECLARE\_WND\_CLASS](../Topic/DECLARE_WND_CLASS.md)|Informações de registros de`CWndClassInfo` para uma classe de nova janela.|  
|[DECLARE\_WND\_CLASS\_EX](../Topic/DECLARE_WND_CLASS_EX.md)|Informações de registros de`CWndClassInfo` para uma classe de nova janela, incluindo os parâmetros da classe.|  
|[DECLARE\_WND\_SUPERCLASS](../Topic/DECLARE_WND_SUPERCLASS.md)|Informações de registros de`CWndClassInfo` para uma classe de janela que é baseada em uma classe existente mas usa um procedimento de janela diferente.  Essa técnica é chamada superclassing.|  
  
 Por padrão, [CWindowImpl](../Topic/CWindowImpl%20Class.md) inclui a macro de `DECLARE_WND_CLASS` para criar uma janela com base em uma classe de nova janela.  Fornece DECLARE\_WND\_CLASS estilos padrão e cor do plano de fundo para o controle.  Se você desejar especificar o estilo e a cor do plano de fundo você mesmo, derive da classe `CWindowImpl` e inclua a macro de `DECLARE_WND_CLASS_EX` em sua definição de classe.  
  
 Se você desejar criar uma janela com base em uma classe existente da janela, derive da classe `CWindowImpl` e inclua a macro de `DECLARE_WND_SUPERCLASS` em sua definição de classe.  Por exemplo:  
  
 [!code-cpp[NVC_ATL_Windowing#43](../../atl/codesnippet/CPP/cwndclassinfo-class_1.h)]  
  
 Para obter mais informações sobre as classes da janela, consulte [Classes de janela](http://msdn.microsoft.com/library/windows/desktop/ms632596) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre como usar o windows em ATL, consulte o artigo [A janela de ATL classes](../Topic/ATL%20Window%20Classes.md).  
  
## Requisitos  
 **Cabeçalho:** atlwin.h  
  
## Consulte também  
 [Classe de CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)