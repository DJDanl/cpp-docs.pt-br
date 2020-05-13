---
title: Classe CMFCDesktopAlertWndInfo
ms.date: 10/18/2018
f1_keywords:
- CMFCDesktopAlertWndInfo
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertWndInfo
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertWndInfo::m_hIcon
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertWndInfo::m_nURLCmdID
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertWndInfo::m_strText
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertWndInfo::m_strURL
helpviewer_keywords:
- CMFCDesktopAlertWndInfo [MFC], m_hIcon
- CMFCDesktopAlertWndInfo [MFC], m_nURLCmdID
- CMFCDesktopAlertWndInfo [MFC], m_strText
- CMFCDesktopAlertWndInfo [MFC], m_strURL
ms.assetid: 5c9bb84e-6c96-4748-8e74-6951b6ae8e84
ms.openlocfilehash: f51c1b75e0c096a34b190e36e097aaca4109b5f8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367582"
---
# <a name="cmfcdesktopalertwndinfo-class"></a>Classe CMFCDesktopAlertWndInfo

A `CMFCDesktopAlertWndInfo` classe é usada com o [CMFCDesktopAlertWnd Class](../../mfc/reference/cmfcdesktopalertwnd-class.md). Ele especifica os controles exibidos se a janela de alerta da área de trabalho aparecer.

## <a name="syntax"></a>Sintaxe

```
class CMFCDesktopAlertWndInfo
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCDesktopAlertWndInfo::~CMFCDesktopAlertWndInfo`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDesktopAlertWndInfo::operador=](#operator_eq)||

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCDesktopAlertWndInfo::m_hIcon](#m_hicon)|Uma alça para o ícone exibido.|
|[CMFCDesktopAlertWndInfo::m_nURLCmdID](#m_nurlcmdid)|O ID de comando associado a um link na janela de alerta da área de trabalho.|
|[CMFCDesktopAlertWndInfo::m_strText](#m_strtext)|O texto exibido na janela de alerta da área de trabalho.|
|[CMFCDesktopAlertWndInfo::m_strURL](#m_strurl)|O link exibido na janela de alerta da área de trabalho.|

## <a name="remarks"></a>Comentários

A `CMFCDesktopAlertWndInfo` classe é passada para o método [CMFCDesktopAlertWnd::Criar](../../mfc/reference/cmfcdesktopalertwnd-class.md#create) para especificar os elementos exibidos na caixa de diálogo padrão da janela de alerta da área de trabalho. A caixa de diálogo padrão pode conter três itens:

- Um ícone, que é definido chamando [CMFCDesktopAlertWndInfo::m_hIcon](#m_hicon).

- Um rótulo, ou mensagem de texto, que é definido ligando para [CMFCDesktopAlertWndInfo::m_strText](#m_strtext).

- Um link, que é definido ligando para [CMFCDesktopAlertWndInfo::m_strURL](#m_strurl). Para definir o comando executado quando o link é clicado, ligue para [CMFCDesktopAlertWndInfo::m_nURLCmdID](#m_nurlcmdid).

Se a caixa de diálogo padrão não for suficiente, você poderá criar uma caixa de diálogo personalizada e passá-la para o método [CMFCDesktopAlertWnd::Criar](../../mfc/reference/cmfcdesktopalertwnd-class.md#create) em vez de usar essa classe. Para obter mais informações, consulte [CMFCDesktopAlertSala .](../../mfc/reference/cmfcdesktopalertdialog-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCDesktopAlertWndInfo` usar vários membros da classe. O exemplo demonstra como definir a alça para o ícone exibido, o texto exibido na janela de alerta da área de trabalho, o link exibido na janela de alerta da área de trabalho e o ID de comando associado a um link na janela de alerta da área de trabalho. Este exemplo faz parte da amostra de [demonstração do alerta de área de trabalho](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DesktopAlertDemo#3](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwndinfo-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cmfcdesktopalertwndinfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxDesktopAlertDiálogo.h

## <a name="cmfcdesktopalertwndinfooperator"></a><a name="operator_eq"></a>CMFCDesktopAlertWndInfo::operador=

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
CMFCDesktopAlertWndInfo& operator=(CMFCDesktopAlertWndInfo& src);
```

### <a name="parameters"></a>Parâmetros

[em] *src*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcdesktopalertwndinfom_hicon"></a><a name="m_hicon"></a>CMFCDesktopAlertWndInfo::m_hIcon

Uma alça para o ícone exibido.

```
HICON m_hIcon;
```

### <a name="remarks"></a>Comentários

## <a name="cmfcdesktopalertwndinfom_nurlcmdid"></a><a name="m_nurlcmdid"></a>CMFCDesktopAlertWndInfo::m_nURLCmdID

O ID de comando associado a um link na janela de alerta da área de trabalho.

```
UINT m_nURLCmdID;
```

### <a name="remarks"></a>Comentários

O ID de comando é enviado ao proprietário da janela pop-up quando o usuário clica no link especificado pelo [CMFCDesktopAlertWndInfo::m_strURL](#m_strurl).

## <a name="cmfcdesktopalertwndinfom_strtext"></a><a name="m_strtext"></a>CMFCDesktopAlertWndInfo::m_strText

O texto exibido na janela de alerta da área de trabalho.

```
CString m_strText;
```

### <a name="remarks"></a>Comentários

## <a name="cmfcdesktopalertwndinfom_strurl"></a><a name="m_strurl"></a>CMFCDesktopAlertWndInfo::m_strURL

O link exibido na janela de alerta da área de trabalho.

```
CString m_strURL;
```

### <a name="remarks"></a>Comentários

Quando o usuário clica no link, o comando que tem o [CMFCDesktopAlertWndInfo::m_nURLCmdID](#m_nurlcmdid) o Comando ID será enviado ao proprietário da janela pop-up.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)<br/>
[CMFCDesktopAlertWnd::Criar](../../mfc/reference/cmfcdesktopalertwnd-class.md#create)<br/>
[Classe CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)
