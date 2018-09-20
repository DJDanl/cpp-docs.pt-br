---
title: Classe CClientDC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CClientDC
- AFXWIN/CClientDC
- AFXWIN/CClientDC::CClientDC
- AFXWIN/CClientDC::m_hWnd
dev_langs:
- C++
helpviewer_keywords:
- CClientDC [MFC], CClientDC
- CClientDC [MFC], m_hWnd
ms.assetid: 8a871d6b-06f8-496e-9fa3-9a5780848369
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3aa255552156fe0bbcb671f39afdcb966e7157ea
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46422175"
---
# <a name="cclientdc-class"></a>Classe CClientDC

Se encarrega de chamar as funções do Windows [GetDC](/windows/desktop/api/winuser/nf-winuser-getdc) na ocasião da construção e [ReleaseDC](/windows/desktop/api/winuser/nf-winuser-releasedc) no tempo de destruição.

## <a name="syntax"></a>Sintaxe

```
class CClientDC : public CDC
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CClientDC::CClientDC](#cclientdc)|Constrói uma `CClientDC` objeto conectado para o `CWnd`.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CClientDC::m_hWnd](#m_hwnd)|O HWND da janela para o qual o `CClientDC` é válido.|

## <a name="remarks"></a>Comentários

Isso significa que o contexto de dispositivo associado com um `CClientDC` objeto é a área de cliente de uma janela.

Para obter mais informações sobre `CClientDC`, consulte [contextos de dispositivo](../../mfc/device-contexts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CDC](../../mfc/reference/cdc-class.md)

`CClientDC`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="cclientdc"></a>  CClientDC::CClientDC

Constrói uma `CClientDC` objeto que acessa a área do cliente a [CWnd](../../mfc/reference/cwnd-class.md) apontado pelo *Apropriei*.

```
explicit CClientDC(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Apropriei*<br/>
A janela cuja área de cliente que acessará o objeto de contexto de dispositivo.

### <a name="remarks"></a>Comentários

O construtor chama a função do Windows [GetDC](/windows/desktop/api/winuser/nf-winuser-getdc).

Uma exceção (do tipo `CResourceException`) será gerada se o Windows `GetDC` chamar falhar. Um contexto de dispositivo pode não estar disponível se o Windows já alocado todos os seus contextos de dispositivo disponíveis. Seu aplicativo compete para os cinco comuns contextos de exibição disponíveis a qualquer momento determinado em Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#42](../../mfc/codesnippet/cpp/cclientdc-class_1.cpp)]

##  <a name="m_hwnd"></a>  CClientDC::m_hWnd

O `HWND` do `CWnd` ponteiro usado para construir o `CClientDC` objeto.

```
HWND m_hWnd;
```

### <a name="remarks"></a>Comentários

*m_hWnd* é uma variável protegida.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CClientDC::CClientDC](#cclientdc).

## <a name="see-also"></a>Consulte também

[Exemplo MFC MDI](../../visual-cpp-samples.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)
