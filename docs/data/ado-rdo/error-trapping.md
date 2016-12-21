---
title: "Intercepta&#231;&#227;o de erro | Microsoft Docs"
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
  - "Controles ActiveX [C++], interceptação de erro"
  - "interceptação de erro [C++]"
ms.assetid: c509b089-a542-44be-8f22-dc5832967a48
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Intercepta&#231;&#227;o de erro
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Em databinding, o ajuste de registro de erro vem de duas fontes: eventos de erro ou objetos de erro.  
  
##  <a name="vcreferrortrappingviaerrorevents"></a> Ajuste de registro de erro nos eventos de erro  
 O controle de dados ADO e os controles de dados de controle de RemoteData RDO têm eventos de erro.  Normalmente, você definir um manipulador de eventos de erro.  Os manipuladores de eventos têm a seguinte assinatura.  
  
```  
void CMyDlg::OnErrorAdodc1(long ErrorNumber,  
                           BSTR* FAR Description,  
                           long Scode,  
                           LPCTSTR Source,  
                           LPCTSTR HelpFile,  
                           long HelpContext,  
                           BOOL FAR* fCancelDisplay)  
```  
  
 O campo de descrição é populado em geral, mas os campos de ErrorNumber e de Scode são populados apenas no caso de erros do.  Um manipulador de eventos padrão deve exibir o campo de descrição em uma caixa de mensagem.  Por exemplo:  
  
```  
{  
   USES_CONVERSION;     
// note: have to include the ATL file ATLConv.h to use the ATL conversion macros  
   ::AfxMessageBox(OLE2T(*Description), MB_OK);  
}  
```  
  
 Entretanto, como o controle de dados ADO e o controle de RemoteData RDO já estarão configuradas para interceptar eventos de erro, nenhuma codificação é necessária.  
  
##  <a name="vcreferrortrappingviaerrorobjects"></a> Ajuste de registro de erro pelos objetos de erro  
 ADO e RDO têm objetos de erro.  Ao gerar [classes wrapper](../../data/ado-rdo/wrapper-classes.md), o controle de RemoteData RDO gerencia wrappers para objetos de erro, mas o controle de dados ADO não.  
  
 O controle de dados ADO automaticamente exibe mensagens de erro ADO.  
  
## Consulte também  
 [Vinculação de dados com controles ActiveX no Visual C\+\+](../../data/ado-rdo/databinding-with-activex-controls-in-visual-cpp.md)