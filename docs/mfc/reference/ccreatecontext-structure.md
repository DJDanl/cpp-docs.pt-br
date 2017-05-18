---
title: Estrutura de CCreateContext | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CCreateContext
dev_langs:
- C++
helpviewer_keywords:
- CCreateContext structure
ms.assetid: 337a0e44-d910-49a8-afc0-c7207666a9dc
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 231f2e44e085d27a2b2cbf289adf7b0521471b0e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ccreatecontext-structure"></a>Estrutura CCreateContext
A estrutura usa a `CCreateContext` estrutura quando ele cria as janelas de quadro e exibições que estão associadas um documento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CCreateContext  
```  
  
## <a name="remarks"></a>Comentários  
 `CCreateContext`é uma estrutura e não tem uma classe base.  
  
 Quando você cria uma janela, os valores nessa estrutura fornecem as informações usadas para conectar os componentes de um documento para o modo de exibição de seus dados. Você só precisa usar `CCreateContext` se você está substituindo as partes do processo de criação.  
  
 Um `CCreateContext` estrutura contém ponteiros para o documento, a janela do quadro, o modo de exibição e o modelo de documento. Ele também contém um ponteiro para um `CRuntimeClass` que identifica o tipo de exibição para criar. As informações de classe de tempo de execução e o ponteiro do documento atual são usados para criar uma nova exibição dinamicamente. A tabela a seguir sugere como e quando cada `CCreateContext` membro pode ser usado:  
  
|Membro|Tipo|O que é para|  
|------------|----------|--------------------|  
|`m_pNewViewClass`|`CRuntimeClass*`|`CRuntimeClass`do modo de exibição para criar novo.|  
|`m_pCurrentDoc`|`CDocument*`|O documento existente a ser associado com a nova exibição.|  
|`m_pNewDocTemplate`|`CDocTemplate*`|O modelo de documento associado com a criação de uma nova janela de quadro MDI.|  
|`m_pLastView`|`CView*`|O modo de exibição original na qual as exibições adicionais são modeladas, como a criação de modos de exibição de janela divisor ou a criação de uma segunda exibição em um documento.|  
|`m_pCurrentFrame`|`CFrameWnd*`|A janela de quadro no qual são modeladas janelas com moldura adicionais, como a criação de uma segunda janela de quadro em um documento.|  
  
 Quando um modelo de documento cria um documento e seus componentes associados, ele valida as informações armazenadas no `CCreateContext` estrutura. Por exemplo, um modo de exibição não deve ser criado para um documento que não existe.  
  
> [!NOTE]
>  Todos os ponteiros em `CCreateContext` são opcionais e podem ser `NULL` se não especificado ou desconhecido.  
  
 `CCreateContext`é usado pelas funções membro listadas em "Consulte também". Consulte as descrições dessas funções para obter informações específicas, se você planeja substituí-los.  
  
 Aqui estão algumas diretrizes gerais:  
  
-   Quando passados como um argumento para a criação da janela, como em `CWnd::Create`, `CFrameWnd::Create`, e `CFrameWnd::LoadFrame`, criar contexto Especifica que a nova janela deve estar conectada. Para a maioria das janelas, toda a estrutura é opcional e um `NULL` ponteiro pode ser passado.  
  
-   Para funções de membro substituíveis, como `CFrameWnd::OnCreateClient`, o `CCreateContext` argumento é opcional.  
  
-   Para funções de membro envolvidas na exibição criação, você deve fornecer informações suficientes para criar o modo de exibição. Por exemplo, para a primeira exibição em uma janela de divisão, você deve fornecer as informações de classe de exibição e o documento atual.  
  
 Em geral, se você usar os padrões do framework, você pode ignorar `CCreateContext`. Se você tentar fazer modificações mais avançadas, o código-fonte biblioteca Microsoft Foundation Class ou programas de exemplo, como VIEWEX, irá guiá-lo. Se você esquecer um parâmetro obrigatório, uma declaração de estrutura informará o que você esqueceu.  
  
 Para obter mais informações sobre `CCreateContext`, consulte o exemplo MFC [VIEWEX](../../visual-cpp-samples.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [CFrameWnd::Create](../../mfc/reference/cframewnd-class.md#create)   
 [CFrameWnd::LoadFrame](../../mfc/reference/cframewnd-class.md#loadframe)   
 [CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient)   
 [CSplitterWnd::Create](../../mfc/reference/csplitterwnd-class.md#create)   
 [CSplitterWnd::CreateView](../../mfc/reference/csplitterwnd-class.md#createview)   
 [CWnd::Create](../../mfc/reference/cwnd-class.md#create)


