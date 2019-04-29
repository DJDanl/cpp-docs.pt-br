---
title: Estrutura CCreateContext
ms.date: 11/04/2016
f1_keywords:
- CCreateContext
helpviewer_keywords:
- CCreateContext structure [MFC]
ms.assetid: 337a0e44-d910-49a8-afc0-c7207666a9dc
ms.openlocfilehash: 795b20cba41eeca8cc1a32e312edf065b718f364
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62347136"
---
# <a name="ccreatecontext-structure"></a>Estrutura CCreateContext

A estrutura usa a `CCreateContext` estrutura quando ele cria as janelas de quadro e exibições que estão associadas um documento.

## <a name="syntax"></a>Sintaxe

```
struct CCreateContext
```

## <a name="remarks"></a>Comentários

`CCreateContext` é uma estrutura e não tem uma classe base.

Quando você cria uma janela, os valores nessa estrutura fornecem as informações usadas para conectar os componentes de um documento para o modo de exibição de seus dados. Você só precisa usar `CCreateContext` se você está substituindo as partes do processo de criação.

Um `CCreateContext` estrutura contém ponteiros para o documento, a janela do quadro, o modo de exibição e o modelo de documento. Ele também contém um ponteiro para um `CRuntimeClass` que identifica o tipo de exibição para criar. As informações de classe de tempo de execução e o ponteiro do documento atual são usados para criar uma nova exibição dinamicamente. A tabela a seguir sugere como e quando cada `CCreateContext` membro pode ser usado:

|Membro|Tipo|O que há para|
|------------|----------|--------------------|
|`m_pNewViewClass`|`CRuntimeClass*`|`CRuntimeClass` da nova exibição para criar.|
|`m_pCurrentDoc`|`CDocument*`|O documento existente a ser associado com a nova exibição.|
|`m_pNewDocTemplate`|`CDocTemplate*`|O modelo de documento associado com a criação de uma nova janela de quadro MDI.|
|`m_pLastView`|`CView*`|O modo de exibição original na qual as exibições adicionais são modeladas, como a criação de modos de exibição do divisor janela ou a criação de uma segunda exibição em um documento.|
|`m_pCurrentFrame`|`CFrameWnd*`|A janela do quadro no qual são modeladas janelas com moldura adicionais, como a criação de uma segunda janela do quadro em um documento.|

Quando um modelo de documento cria um documento e seus componentes associados, ele valida as informações armazenadas em do `CCreateContext` estrutura. Por exemplo, um modo de exibição não deve ser criado para um documento inexistente.

> [!NOTE]
>  Todos os ponteiros na `CCreateContext` são opcionais e podem ser `NULL` se não especificado ou desconhecido.

`CCreateContext` é usado pelas funções membro listadas em "Consulte também". Consulte as descrições dessas funções para obter informações específicas, se você planeja substituí-las.

Aqui estão algumas diretrizes gerais:

- Quando passado como um argumento para a criação da janela, como em `CWnd::Create`, `CFrameWnd::Create`, e `CFrameWnd::LoadFrame`, o contexto de criar Especifica que a nova janela deve ser conectada. Para a maioria das janelas, a estrutura inteira é opcional e um `NULL` ponteiro pode ser passado.

- Para funções de membro substituíveis, tais como `CFrameWnd::OnCreateClient`, o `CCreateContext` argumento é opcional.

- Para funções de membro envolvidas na exibição criação, você deve fornecer informações suficientes para criar a exibição. Por exemplo, para a primeira exibição em uma janela separadora, você deve fornecer as informações de classe de exibição e o documento atual.

Em geral, se você usar os padrões de estrutura, você pode ignorar `CCreateContext`. Se você tentar modificações mais avançadas, o código-fonte de biblioteca Microsoft Foundation Class ou programas de exemplo, como VIEWEX, irá guiá-lo. Se você esquecer um parâmetro obrigatório, uma declaração de estrutura lhe dirá o que você se esqueceu.

Para obter mais informações sobre `CCreateContext`, consulte o exemplo MFC [VIEWEX](../../overview/visual-cpp-samples.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CFrameWnd::Create](../../mfc/reference/cframewnd-class.md#create)<br/>
[CFrameWnd::LoadFrame](../../mfc/reference/cframewnd-class.md#loadframe)<br/>
[CFrameWnd::OnCreateClient](../../mfc/reference/cframewnd-class.md#oncreateclient)<br/>
[CSplitterWnd::Create](../../mfc/reference/csplitterwnd-class.md#create)<br/>
[CSplitterWnd::CreateView](../../mfc/reference/csplitterwnd-class.md#createview)<br/>
[CWnd::Create](../../mfc/reference/cwnd-class.md#create)
