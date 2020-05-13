---
title: Classe COleConvertDialog
ms.date: 11/04/2016
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
ms.openlocfilehash: 6d6690b8d06df29ce9fcd323eb8724009ee3cca9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366173"
---
# <a name="coleconvertdialog-class"></a>Classe COleConvertDialog

Para obter mais informações, consulte a estrutura [OLEUICONVERT](/windows/win32/api/oledlg/ns-oledlg-oleuiconvertw) no SDK do Windows.

## <a name="syntax"></a>Sintaxe

```
class COleConvertDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleConvertDiálogo::COleConvertDialog](#coleconvertdialog)|Constrói um objeto `COleConvertDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleConvertDiálogo::DoConvert](#doconvert)|Executa a conversão especificada na caixa de diálogo.|
|[COleConvertDialog::DoModal](#domodal)|Exibe a caixa de diálogo OLE Change Item.|
|[COleConvertDialog::GetClassID](#getclassid)|Obtém o CLSID associado ao item escolhido.|
|[COleConvertDiálogo::GetDrawAspect](#getdrawaspect)|Especifica se deve desenhar o item como um ícone.|
|[COleConvertDiálogo::GetIconicMetafile](#geticonicmetafile)|Obtém uma alça para o metaarquivo associado à forma icônica deste item.|
|[COleConvertDiálogo::GetSelectionType](#getselectiontype)|Recebe o tipo de seleção escolhida.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleConvertDialog::m_cv](#m_cv)|Uma estrutura que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

> [!NOTE]
> O código de contêiner gerado pelo Assistente do aplicativo usa essa classe.

Para obter mais informações sobre caixas de diálogo específicas da OLE, consulte o artigo [Caixas de Diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

[Coledialog](../../mfc/reference/coledialog-class.md)

`COleConvertDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

## <a name="coleconvertdialogcoleconvertdialog"></a><a name="coleconvertdialog"></a>COleConvertDiálogo::COleConvertDialog

Constrói apenas `COleConvertDialog` um objeto.

```
explicit COleConvertDialog (
    COleClientItem* pItem,
    DWORD dwFlags = CF_SELECTCONVERTTO,
    CLSID* pClassID = NULL,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Aponta para o item a ser convertido ou ativado.

*dwFlags*<br/>
Sinalizador de criação, que contém qualquer número dos seguintes valores combinados usando o bitwise ou operador:

- CF_SELECTCONVERTTO Especifica que o botão Converter para rádio será selecionado inicialmente quando a caixa de diálogo for chamada. Esse é o padrão.

- CF_SELECTACTIVATEAS Especifica que o botão Ativar como rádio será selecionado inicialmente quando a caixa de diálogo for chamada.

- CF_SETCONVERTDEFAULT Especifica que a classe cujo CLSID `clsidConvertDefault` é `m_cv` especificado pelo membro da estrutura será usada como seleção padrão na caixa de lista de classes quando o botão Converter para rádio for selecionado.

- CF_SETACTIVATEDEFAULT Especifica que a classe cujo CLSID `clsidActivateDefault` é `m_cv` especificado pelo membro da estrutura será usada como seleção padrão na caixa de lista de classes quando o botão Ativar como rádio for selecionado.

- CF_SHOWHELPBUTTON Especifica que o botão Ajuda será exibido quando a caixa de diálogo for chamada.

*Pclassid*<br/>
Aponta para o CLSID do item a ser convertido ou ativado. Se NULA, o CLSID associado ao *pItem* será usado.

*Pparentwnd*<br/>
Aponta para o objeto da janela `CWnd`pai ou proprietário (de tipo) ao qual o objeto de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida na janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo, ligue para a função [DoModal.](#domodal)

Para obter mais informações, consulte [a tecla CLSID](/windows/win32/com/clsid-key-hklm) e a estrutura [OLEUICONVERT.](/windows/win32/api/oledlg/ns-oledlg-oleuiconvertw)

## <a name="coleconvertdialogdoconvert"></a><a name="doconvert"></a>COleConvertDiálogo::DoConvert

Chame esta função, depois de retornar com sucesso do [DoModal,](#domodal)seja para converter ou ativar um objeto do tipo [COleClientItem](../../mfc/reference/coleclientitem-class.md).

```
BOOL DoConvert(COleClientItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Aponta para o item a ser convertido ou ativado. Não pode ser NULL.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O item é convertido ou ativado de acordo com as informações selecionadas pelo usuário na caixa de diálogo Converter.

## <a name="coleconvertdialogdomodal"></a><a name="domodal"></a>COleConvertDialog::DoModal

Chame esta função para exibir a caixa de diálogo OLE Converter.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com sucesso.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se o IDABORT for retornado, ligue para a função de membro [COleDialog::GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte a função [OleUIConvert](/windows/win32/api/oledlg/nf-oledlg-oleuiconvertw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo `DoModal`membros da estrutura [m_cv,](#m_cv) você deve fazer isso antes de chamar, mas depois que o objeto de diálogo for construído.

Se `DoModal` retornar o IDOK, você pode ligar para outras funções de membro para recuperar as configurações ou informações que foram inseridas pelo usuário na caixa de diálogo.

## <a name="coleconvertdialoggetclassid"></a><a name="getclassid"></a>COleConvertDialog::GetClassID

Chame esta função para obter o CLSID associado ao item que o usuário selecionou na caixa de diálogo Converter.

```
REFCLSID GetClassID() const;
```

### <a name="return-value"></a>Valor retornado

O CLSID associado ao item selecionado na caixa de diálogo Converter.

### <a name="remarks"></a>Comentários

Ligue para esta função somente depois que [o DoModal](#domodal) retornar o IDOK.

Para obter mais informações, consulte [a tecla CLSID](/windows/win32/com/clsid-key-hklm) no SDK do Windows.

## <a name="coleconvertdialoggetdrawaspect"></a><a name="getdrawaspect"></a>COleConvertDiálogo::GetDrawAspect

Chame esta função para determinar se o usuário escolheu exibir o item selecionado como um ícone.

```
DVASPECT GetDrawAspect() const;
```

### <a name="return-value"></a>Valor retornado

O método necessário para renderizar o objeto.

- DVASPECT_CONTENT Retornado se a caixa de seleção Exibir como ícone não foi verificada.

- DVASPECT_ICON retornado se a caixa de seleção Exibir como ícone foi verificada.

### <a name="remarks"></a>Comentários

Ligue para esta função somente depois que [o DoModal](#domodal) retornar o IDOK.

Para obter mais informações sobre o aspecto de desenho, consulte a estrutura de dados [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

## <a name="coleconvertdialoggeticonicmetafile"></a><a name="geticonicmetafile"></a>COleConvertDiálogo::GetIconicMetafile

Chame esta função para obter uma alça para o metaarquivo que contém o aspecto icônico do item selecionado.

```
HGLOBAL GetIconicMetafile() const;
```

### <a name="return-value"></a>Valor retornado

A alça para o metaarquivo contendo o aspecto icônico do item selecionado, se a caixa de seleção Exibir como ícone foi verificada quando a caixa de diálogo foi rejeitada escolhendo OK; caso contrário, NULL.

## <a name="coleconvertdialoggetselectiontype"></a><a name="getselectiontype"></a>COleConvertDiálogo::GetSelectionType

Chame esta função para determinar o tipo de conversão selecionada na caixa de diálogo Converter.

```
UINT GetSelectionType() const;
```

### <a name="return-value"></a>Valor retornado

Tipo de seleção feita.

### <a name="remarks"></a>Comentários

Os valores do tipo `Selection` de retorno são especificados `COleConvertDialog` pelo tipo de enumeração declarado na classe.

```
enum Selection {
    noConversion,
    convertItem,
    activateAs
    };
```

Breves descrições desses valores seguem:

- `COleConvertDialog::noConversion`Devolvido se a caixa de diálogo foi cancelada ou o usuário não selecionou nenhuma conversão. Se `COleConvertDialog::DoModal` o IDOK retornado, é possível que o usuário selecione um ícone diferente do selecionado anteriormente.

- `COleConvertDialog::convertItem`Devolvido se o botão Converter para rádio foi verificado, o usuário `DoModal` selecionou um item diferente para converter e retornou o IDOK.

- `COleConvertDialog::activateAs`Retornado se o botão Ativar como rádio foi verificado, o `DoModal` usuário selecionou um item diferente para ativar e retornou o IDOK.

## <a name="coleconvertdialogm_cv"></a><a name="m_cv"></a>COleConvertDialog::m_cv

Estrutura do tipo OLEUICONVERT usada para controlar o comportamento da caixa de diálogo Converter.

```
OLEUICONVERT m_cv;
```

### <a name="remarks"></a>Comentários

Os membros desta estrutura podem ser modificados diretamente ou através de funções de membros.

Para obter mais informações, consulte a estrutura [OLEUICONVERT](/windows/win32/api/oledlg/ns-oledlg-oleuiconvertw) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
