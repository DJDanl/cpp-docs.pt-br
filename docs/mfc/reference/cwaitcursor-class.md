---
title: Classe CWaitCursor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CWaitCursor
- AFXWIN/CWaitCursor
- AFXWIN/CWaitCursor::CWaitCursor
- AFXWIN/CWaitCursor::Restore
dev_langs:
- C++
helpviewer_keywords:
- CWaitCursor [MFC], CWaitCursor
- CWaitCursor [MFC], Restore
ms.assetid: 5dfae2ff-d7b6-4383-b0ad-91e0868c67b3
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1cf5c850158e445e7695b85e540b1e0c162e621c
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="cwaitcursor-class"></a>Classe CWaitCursor
Fornece uma maneira de uma linha para mostrar um cursor de espera, que normalmente é exibido como uma ampulheta enquanto você estiver fazendo uma operação demorada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CWaitCursor  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWaitCursor::CWaitCursor](#cwaitcursor)|Constrói um `CWaitCursor` do objeto e exibe o cursor de espera.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWaitCursor::Restore](#restore)|Restaura o cursor de espera depois que ela tiver sido alterada.|  
  
## <a name="remarks"></a>Comentários  
 `CWaitCursor`não tem uma classe base.  
  
 Windows boa práticas de programação exigir que você exibir um cursor de espera, sempre que você está executando uma operação que leva uma quantidade considerável de tempo.  
  
 Para exibir um cursor de espera, basta definir um `CWaitCursor` variável antes do código que executa a operação demorada. O construtor do objeto automaticamente faz com que o cursor de espera para ser exibido.  
  
 Quando o objeto sai do escopo (no final do bloco no qual o `CWaitCursor` objeto for declarado), seu destruidor define o cursor até o cursor anterior. Em outras palavras, o objeto executa automaticamente a limpeza necessária.  
  
> [!NOTE]
>  Devido a seus construtores e destruidores funcionam, `CWaitCursor` objetos sempre são declarados como variáveis locais — nunca são declaradas como variáveis globais, nem são alocados com **novo**.  
  
 Se você executar uma operação que pode fazer com que o cursor seja alterado, como exibir uma caixa de mensagem ou a caixa de diálogo, a chamada a [restaurar](#restore) função de membro para restaurar o cursor de espera. É okey chamar **restaurar** mesmo quando um cursor de espera é exibido atualmente.  
  
 Outra maneira de exibir um cursor de espera é usar a combinação de [CCmdTarget::BeginWaitCursor](../../mfc/reference/ccmdtarget-class.md#beginwaitcursor), [CCmdTarget::EndWaitCursor](../../mfc/reference/ccmdtarget-class.md#endwaitcursor)e talvez [CCmdTarget::RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor). No entanto, `CWaitCursor` é mais fácil de usar porque você não precisa definir o cursor até o cursor anterior quando você concluiu a operação demorada.  
  
> [!NOTE]
>  MFC define e restaura o cursor usando o [CWinApp::DoWaitCursor](../../mfc/reference/cwinapp-class.md#dowaitcursor) função virtual. Você pode substituir essa função para fornecer um comportamento personalizado.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CWaitCursor`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#62](../../mfc/reference/codesnippet/cpp/cwaitcursor-class_1.cpp)]  
  
##  <a name="cwaitcursor"></a>CWaitCursor::CWaitCursor  
 Para exibir um cursor de espera, basta declarar uma `CWaitCursor` objeto antes do código que executa a operação demorada.  
  
```  
CWaitCursor();
```  
  
### <a name="remarks"></a>Comentários  
 O construtor automaticamente faz com que o cursor de espera para ser exibido.  
  
 Quando o objeto sai do escopo (no final do bloco no qual o `CWaitCursor` objeto for declarado), seu destruidor define o cursor até o cursor anterior. Em outras palavras, o objeto executa automaticamente a limpeza necessária.  
  
 Você pode tirar proveito do fato de que o destruidor é chamado no final do bloco (que pode ser antes do final da função) para tornar o cursor de espera ativa apenas parte de sua função. Essa técnica é mostrada no segundo exemplo abaixo.  
  
> [!NOTE]
>  Devido a seus construtores e destruidores funcionam, `CWaitCursor` objetos sempre são declarados como variáveis locais — nunca são declaradas como variáveis globais, nem são alocados com **novo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#63](../../mfc/reference/codesnippet/cpp/cwaitcursor-class_2.cpp)]  
  
##  <a name="restore"></a>CWaitCursor::Restore  
 Para restaurar o cursor de espera, chame essa função depois de executar uma operação, como exibir uma caixa de mensagem ou caixa de diálogo que pode alterar o cursor de espera para outro cursor.  
  
```  
void Restore();
```  
  
### <a name="remarks"></a>Comentários  
 É Okey para chamar **restaurar** mesmo quando o cursor de espera é exibido atualmente.  
  
 Se você precisar restaurar o cursor de espera enquanto estiver em uma função diferente no qual o `CWaitCursor` objeto for declarado, você pode chamar [CCmdTarget::RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#64](../../mfc/reference/codesnippet/cpp/cwaitcursor-class_3.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [CCmdTarget::BeginWaitCursor](../../mfc/reference/ccmdtarget-class.md#beginwaitcursor)   
 [CCmdTarget::EndWaitCursor](../../mfc/reference/ccmdtarget-class.md#endwaitcursor)   
 [CCmdTarget::RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor)   
 [CWinApp::DoWaitCursor](../../mfc/reference/cwinapp-class.md#dowaitcursor)   
 [Como alterar o Cursor do Mouse em um aplicativo do Microsoft Foundation classe i:](http://go.microsoft.com/fwlink/p/?linkid=128044)



