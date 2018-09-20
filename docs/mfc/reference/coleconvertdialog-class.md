---
title: Classe COleConvertDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleConvertDialog
- AFXODLGS/COleConvertDialog
- AFXODLGS/COleConvertDialog::COleConvertDialog
- AFXODLGS/COleConvertDialog::DoConvert
- AFXODLGS/COleConvertDialog::DoModal
- AFXODLGS/COleConvertDialog::GetClassID
- AFXODLGS/COleConvertDialog::GetDrawAspect
- AFXODLGS/COleConvertDialog::GetIconicMetafile
- AFXODLGS/COleConvertDialog::GetSelectionType
- AFXODLGS/COleConvertDialog::m_cv
dev_langs:
- C++
helpviewer_keywords:
- COleConvertDialog [MFC], COleConvertDialog
- COleConvertDialog [MFC], DoConvert
- COleConvertDialog [MFC], DoModal
- COleConvertDialog [MFC], GetClassID
- COleConvertDialog [MFC], GetDrawAspect
- COleConvertDialog [MFC], GetIconicMetafile
- COleConvertDialog [MFC], GetSelectionType
- COleConvertDialog [MFC], m_cv
ms.assetid: a7c57714-31e8-4b78-834d-8ddd1b856a1c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b1ff8047e6d7291fe55619d8b0a3eabb877b728a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46436528"
---
# <a name="coleconvertdialog-class"></a>Classe COleConvertDialog

Para obter mais informações, consulte o [OLEUICONVERT](/windows/desktop/api/oledlg/ns-oledlg-tagoleuiconverta) estrutura no SDK do Windows.

## <a name="syntax"></a>Sintaxe

```
class COleConvertDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleConvertDialog::COleConvertDialog](#coleconvertdialog)|Constrói um objeto `COleConvertDialog`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleConvertDialog::DoConvert](#doconvert)|Executa a conversão especificada na caixa de diálogo.|
|[COleConvertDialog::DoModal](#domodal)|Exibe a caixa de diálogo de Item de alteração OLE.|
|[COleConvertDialog::GetClassID](#getclassid)|Obtém o CLSID associado ao item escolhido.|
|[COleConvertDialog::GetDrawAspect](#getdrawaspect)|Especifica se deve desenhar o item como um ícone.|
|[COleConvertDialog::GetIconicMetafile](#geticonicmetafile)|Obtém um identificador para o metarquivo associado ao formulário icônico deste item.|
|[COleConvertDialog::GetSelectionType](#getselectiontype)|Obtém o tipo de seleção escolhida.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleConvertDialog::m_cv](#m_cv)|Uma estrutura que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

> [!NOTE]
>  Código do contêiner gerado pelo Assistente de aplicativo usa essa classe.

Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

[COleDialog](../../mfc/reference/coledialog-class.md)

`COleConvertDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

##  <a name="coleconvertdialog"></a>  COleConvertDialog::COleConvertDialog

Constrói a apenas um `COleConvertDialog` objeto.

```
explicit COleConvertDialog (
    COleClientItem* pItem,
    DWORD dwFlags = CF_SELECTCONVERTTO,
    CLSID* pClassID = NULL,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Aponta para o item a ser convertido ou ativado.

*dwFlags*<br/>
Sinalizador de criação, que contém qualquer número de valores a seguir combinadas que usam o bit a bit- ou operador:

- CF_SELECTCONVERTTO Especifica que o botão de opção de converter para será inicialmente selecionado quando a caixa de diálogo é chamada. Esse é o padrão.

- CF_SELECTACTIVATEAS Especifica que o botão de opção Ativar como serão selecionadas inicialmente quando a caixa de diálogo é chamada.

- CF_SETCONVERTDEFAULT Especifica que a classe cujo CLSID especificado pelo `clsidConvertDefault` membro do `m_cv` estrutura será usada como a seleção padrão na caixa de listagem de classe quando o botão de opção de converter para está selecionado.

- CF_SETACTIVATEDEFAULT Especifica que a classe cujo CLSID especificado pelo `clsidActivateDefault` membro do `m_cv` estrutura será usada como a seleção padrão na caixa de listagem de classe quando o botão de opção Ativar como está selecionado.

- CF_SHOWHELPBUTTON Especifica que o botão de Ajuda será exibido quando a caixa de diálogo é chamada.

*pClassID*<br/>
Aponta para o CLSID do item a ser convertido ou ativado. Se for NULL, o CLSID associado *pItem* será usado.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietária (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for NULL, a janela pai da caixa de diálogo é definida para a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo, chame o [DoModal](#domodal) função.

Para obter mais informações, consulte [chave CLSID](/windows/desktop/com/clsid-key-hklm) e o [OLEUICONVERT](/windows/desktop/api/oledlg/ns-oledlg-tagoleuiconverta) estrutura.

##  <a name="doconvert"></a>  COleConvertDialog::DoConvert

Chame essa função, após retornar com êxito do [DoModal](#domodal), seja para converter ou ativar um objeto do tipo [COleClientItem](../../mfc/reference/coleclientitem-class.md).

```
BOOL DoConvert(COleClientItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Aponta para o item a ser convertido ou ativado. Não pode ser NULL.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O item é convertido ou ativado de acordo com as informações selecionadas pelo usuário na caixa de diálogo Converter.

##  <a name="domodal"></a>  COleConvertDialog::DoModal

Chame essa função para exibir a caixa de diálogo converter OLE.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

Status de conclusão para a caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com êxito.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame o [COleDialog::GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIConvert](/windows/desktop/api/oledlg/nf-oledlg-oleuiconverta) função no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles de caixa de diálogo definindo membros do [m_cv](#m_cv) estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.

Se `DoModal` retorna IDOK, você pode chamar outro membro funções para recuperar as configurações ou informações que era inseridas pelo usuário na caixa de diálogo.

##  <a name="getclassid"></a>  COleConvertDialog::GetClassID

Chame essa função para obter o CLSID associado ao item o usuário selecionado na caixa de diálogo Converter.

```
REFCLSID GetClassID() const;
```

### <a name="return-value"></a>Valor de retorno

O CLSID associado ao item que foi selecionado na caixa de diálogo Converter.

### <a name="remarks"></a>Comentários

Chamada para essa função somente após [DoModal](#domodal) retorna IDOK.

Para obter mais informações, consulte [chave CLSID](/windows/desktop/com/clsid-key-hklm) no SDK do Windows.

##  <a name="getdrawaspect"></a>  COleConvertDialog::GetDrawAspect

Chame essa função para determinar se o usuário optou por exibir o item selecionado como um ícone.

```
DVASPECT GetDrawAspect() const;
```

### <a name="return-value"></a>Valor de retorno

O método necessário para processar o objeto.

- DVASPECT_CONTENT retornado se a caixa de seleção Exibir como ícone não foi verificada.

- DVASPECT_ICON retornado se a caixa de seleção Exibir como ícone foi verificada.

### <a name="remarks"></a>Comentários

Chamada para essa função somente após [DoModal](#domodal) retorna IDOK.

Para obter mais informações sobre o aspecto de desenho, consulte o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura de dados no SDK do Windows.

##  <a name="geticonicmetafile"></a>  COleConvertDialog::GetIconicMetafile

Chame essa função para obter um identificador para o metarquivo que contém o aspecto icônico do item selecionado.

```
HGLOBAL GetIconicMetafile() const;
```

### <a name="return-value"></a>Valor de retorno

O identificador para o metarquivo que contém o aspecto icônico do item selecionado, se a caixa de seleção Exibir como ícone tiver sido verificada quando a caixa de diálogo foi ignorada, escolhendo Okey; Caso contrário, nulo.

##  <a name="getselectiontype"></a>  COleConvertDialog::GetSelectionType

Chame essa função para determinar o tipo de conversão selecionada na caixa de diálogo Converter.

```
UINT GetSelectionType() const;
```

### <a name="return-value"></a>Valor de retorno

Tipo de seleção feita.

### <a name="remarks"></a>Comentários

Os valores de tipo de retorno são especificados pela `Selection` tipo de enumeração declarado no `COleConvertDialog` classe.

```
enum Selection {
    noConversion,
    convertItem,
    activateAs
    };
```

Execute as breves descrições desses valores:

- `COleConvertDialog::noConversion` Retornado se a caixa de diálogo foi cancelada ou que o usuário não selecionou nenhuma conversão. Se `COleConvertDialog::DoModal` retornado IDOK, é possível que o usuário selecionou um ícone diferente daquele selecionado anteriormente.

- `COleConvertDialog::convertItem` Retornado se o botão de opção de converter para foi marcado, o usuário selecionou um item diferente para converter, e `DoModal` retornado IDOK.

- `COleConvertDialog::activateAs` Retornado se o botão de opção Ativar que foi marcado, o usuário selecionou um item diferente para ser ativado, e `DoModal` retornado IDOK.

##  <a name="m_cv"></a>  COleConvertDialog::m_cv

Estrutura do tipo OLEUICONVERT usado para controlar o comportamento da caixa de diálogo Converter.

```
OLEUICONVERT m_cv;
```

### <a name="remarks"></a>Comentários

Os membros dessa estrutura podem ser modificados diretamente ou através de funções de membro.

Para obter mais informações, consulte o [OLEUICONVERT](/windows/desktop/api/oledlg/ns-oledlg-tagoleuiconverta) estrutura no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
