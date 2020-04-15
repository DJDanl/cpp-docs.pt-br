---
title: Classe COlePropertiesDialog
ms.date: 11/04/2016
f1_keywords:
- COlePropertiesDialog
- AFXODLGS/COlePropertiesDialog
- AFXODLGS/COlePropertiesDialog::COlePropertiesDialog
- AFXODLGS/COlePropertiesDialog::DoModal
- AFXODLGS/COlePropertiesDialog::OnApplyScale
- AFXODLGS/COlePropertiesDialog::m_gp
- AFXODLGS/COlePropertiesDialog::m_lp
- AFXODLGS/COlePropertiesDialog::m_op
- AFXODLGS/COlePropertiesDialog::m_psh
- AFXODLGS/COlePropertiesDialog::m_vp
helpviewer_keywords:
- COlePropertiesDialog [MFC], COlePropertiesDialog
- COlePropertiesDialog [MFC], DoModal
- COlePropertiesDialog [MFC], OnApplyScale
- COlePropertiesDialog [MFC], m_gp
- COlePropertiesDialog [MFC], m_lp
- COlePropertiesDialog [MFC], m_op
- COlePropertiesDialog [MFC], m_psh
- COlePropertiesDialog [MFC], m_vp
ms.assetid: a54dbc89-1447-4329-bd01-00e98ec9e935
ms.openlocfilehash: f065894ff49af755ab4020f71b0213b19db49054
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374890"
---
# <a name="colepropertiesdialog-class"></a>Classe COlePropertiesDialog

Encapsula a caixa de diálogo Propriedades de objeto OLE comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class COlePropertiesDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COlePropertiesDiálogo::COlePropertiesDiálogo](#colepropertiesdialog)|Constrói um objeto `COlePropertiesDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COlePropertiesDiálogo::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|
|[COlePropertiesDialog::OnApplyScale](#onapplyscale)|Chamado pelo framework quando o dimensionamento do item do documento foi alterado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COlePropertiesDiálogo::m_gp](#m_gp)|Uma estrutura usada para inicializar a `COlePropertiesDialog` página "Geral" de um objeto.|
|[COlePropertiesDiálogo::m_lp](#m_lp)|Uma estrutura usada para inicializar a `COlePropertiesDialog` página "Link" de um objeto.|
|[COlePropertiesDiálogo::m_op](#m_op)|Uma estrutura usada para `COlePropertiesDialog` inicializar o objeto.|
|[COlePropertiesDiálogo::m_psh](#m_psh)|Uma estrutura usada para adicionar páginas de propriedade personalizadas adicionais.|
|[COlePropertiesDiálogo::m_vp](#m_vp)|Uma estrutura usada para personalizar a `COlePropertiesDialog` página "Exibir" de um objeto.|

## <a name="remarks"></a>Comentários

As caixas de diálogo Common OLE Object Properties fornecem uma maneira fácil de exibir e modificar as propriedades de um item de documento OLE de forma consistente com os padrões do Windows. Essas propriedades incluem, entre outras, informações no arquivo representado pelo item do documento, opções para exibir o ícone e o dimensionamento da imagem e informações no link do item (se o item estiver vinculado).

Para usar `COlePropertiesDialog` um objeto, primeiro `COlePropertiesDialog` crie o objeto usando o construtor. Depois que a caixa de diálogo `DoModal` for construída, ligue para a função membro para exibir a caixa de diálogo e permita que o usuário modifique quaisquer propriedades do item. `DoModal`retorna se o usuário selecionou o botão OK (IDOK) ou IDCANCEL (IDCANCEL). Além dos botões OK e Cancel, há um botão Aplicar. Quando o usuário seleciona Aplicar, quaisquer alterações feitas nas propriedades do item do documento são aplicadas ao item e sua imagem é atualizada automaticamente, mas permanece ativa.

O [m_psh](#m_psh) membro de dados `PROPSHEETHEADER` é um ponteiro para uma estrutura e, na maioria dos casos, você não precisará acessá-lo explicitamente. Uma exceção é quando você precisa de páginas de propriedade adicionais além das páginas padrão Geral, Exibição e Link. Neste caso, você pode `m_psh` modificar o membro de dados `DoModal` para incluir suas páginas personalizadas antes de chamar a função de membro.

Para obter mais informações sobre caixas de diálogo OLE, consulte o artigo [Caixas de Diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

[Coledialog](../../mfc/reference/coledialog-class.md)

`COlePropertiesDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

## <a name="colepropertiesdialogcolepropertiesdialog"></a><a name="colepropertiesdialog"></a>COlePropertiesDiálogo::COlePropertiesDiálogo

Cria um objeto `COlePropertiesDialog`.

```
COlePropertiesDialog(
    COleClientItem* pItem,
    UINT nScaleMin = 10,
    UINT nScaleMax = 500,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Ponteiro para o item do documento cujas propriedades estão sendo acessadas.

*nScaleMin*<br/>
Porcentagem mínima de dimensionamento para a imagem do item do documento.

*nScaleMax*<br/>
Porcentagem máxima de dimensionamento para a imagem do item do documento.

*Pparentwnd*<br/>
Ponteiro para o pai ou proprietário da caixa de diálogo.

### <a name="remarks"></a>Comentários

Obtenha sua classe de diálogo `COlePropertiesDialog` Propriedades de objeto OLE comum para implementar o dimensionamento de seus itens de documento. Quaisquer caixas de diálogo implementadas por uma instância desta classe não suportarão o dimensionamento do item do documento.

Por padrão, a caixa de diálogo Propriedades de objeto OLE comum tem três páginas padrão:

- Geral

   Esta página contém informações do sistema para o arquivo representado pelo item do documento selecionado. A partir desta página, o usuário pode converter o item selecionado para outro tipo.

- Visualizar

   Esta página contém opções para exibir o item, alterar o ícone e alterar o dimensionamento da imagem.

- Link

   Esta página contém opções para alterar a localização do item vinculado e atualizar o item vinculado. A partir desta página, o usuário pode quebrar o link do item selecionado.

Para adicionar páginas além daquelas fornecidas por padrão, modifique a `COlePropertiesDialog`variável de membro [m_psh](#m_psh) antes de sair do construtor de sua classe derivada. Esta é uma implementação avançada da `COlePropertiesDialog` construtora.

## <a name="colepropertiesdialogdomodal"></a><a name="domodal"></a>COlePropertiesDiálogo::DoModal

Chame esta função de membro para exibir a caixa de diálogo Propriedades de objeto OLE comum do Windows e permitir que o usuário visualize e/ou altere as várias propriedades do item do documento.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

IDOK ou IDCANCEL se forbem bem sucedido; caso contrário, 0. IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão OK ou Cancel.

Se o IDCANCEL for retornado, você pode ligar para a função [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro.

## <a name="colepropertiesdialogm_gp"></a><a name="m_gp"></a>COlePropertiesDiálogo::m_gp

Uma estrutura do tipo [OLEUIGNRLPROPS,](/windows/win32/api/oledlg/ns-oledlg-oleuignrlpropsw)usada para inicializar a página geral da caixa de diálogo Propriedades do Objeto OLE.

```
OLEUIGNRLPROPS m_gp;
```

### <a name="remarks"></a>Comentários

Esta página mostra o tipo e o tamanho de uma incorporação e permite que o usuário acesse a caixa de diálogo Converter. Esta página também mostra o destino do link se o objeto for um link.

Para obter mais `OLEUIGNRLPROPS` informações sobre a estrutura, consulte o Windows SDK.

## <a name="colepropertiesdialogm_lp"></a><a name="m_lp"></a>COlePropertiesDiálogo::m_lp

Uma estrutura do tipo [OLEUILINKPROPS,](/windows/win32/api/oledlg/ns-oledlg-oleuilinkpropsw)usada para inicializar a página Link da caixa de diálogo Propriedades do objeto OLE.

```
OLEUILINKPROPS m_lp;
```

### <a name="remarks"></a>Comentários

Esta página mostra a localização do item vinculado e permite que o usuário atualize ou quebre o link para o item.

Para obter mais `OLEUILINKPROPS` informações sobre a estrutura, consulte o Windows SDK.

## <a name="colepropertiesdialogm_op"></a><a name="m_op"></a>COlePropertiesDiálogo::m_op

Uma estrutura do tipo [OLEUIOBJECTPROPS,](/windows/win32/api/oledlg/ns-oledlg-oleuiobjectpropsw)usada para inicializar a caixa de diálogo Propriedades de Objeto OLE comum.

```
OLEUIOBJECTPROPS m_op;
```

### <a name="remarks"></a>Comentários

Essa estrutura contém membros usados para inicializar as páginas Geral, Link e Exibir.

Para obter mais informações, consulte as estruturas OLEUIOBJECTPROPS e [OLEUILINKPROPS](/windows/win32/api/oledlg/ns-oledlg-oleuilinkpropsw) no SDK do Windows.

## <a name="colepropertiesdialogm_psh"></a><a name="m_psh"></a>COlePropertiesDiálogo::m_psh

Uma estrutura do tipo [PROPSHEETHEADER](/windows/win32/api/prsht/ns-prsht-propsheetheadera_v2), cujos membros armazenam as características do objeto de diálogo.

```
PROPSHEETHEADER m_psh;
```

### <a name="remarks"></a>Comentários

Depois de `COlePropertiesDialog` construir um objeto, você pode usar `m_psh` para definir `DoModal` vários aspectos da caixa de diálogo antes de chamar a função de membro.

Se você `m_psh` modificar o membro de dados diretamente, você substituirá qualquer comportamento padrão.

Para obter mais `PROPSHEETHEADER` informações sobre a estrutura, consulte o Windows SDK.

## <a name="colepropertiesdialogm_vp"></a><a name="m_vp"></a>COlePropertiesDiálogo::m_vp

Uma estrutura do tipo [OLEUIVIEWPROPS,](/windows/win32/api/oledlg/ns-oledlg-oleuiviewpropsw)usada para inicializar a página Exibir da caixa de diálogo Propriedades do objeto OLE.

```
OLEUIVIEWPROPS m_vp;
```

### <a name="remarks"></a>Comentários

Esta página permite que o usuário alterne entre as visualizações "conteúdo" e "icônicas" do objeto e altere seu dimensionamento dentro do recipiente. Ele também permite que o usuário acesse a caixa de diálogo Alterar ícone quando o objeto está sendo exibido como um ícone.

Para obter mais `OLEUIVIEWPROPS` informações sobre a estrutura, consulte o Windows SDK.

## <a name="colepropertiesdialogonapplyscale"></a><a name="onapplyscale"></a>COlePropertiesDialog::OnApplyScale

Chamado pelo framework quando o valor de dimensionamento foi alterado e ok ou aplicar foi selecionado.

```
virtual BOOL OnApplyScale(
    COleClientItem* pItem,
    int nCurrentScale,
    BOOL bRelativeToOrig);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Ponteiro para o item do documento cujas propriedades estão sendo acessadas.

*nCurrentScale*<br/>
Valor numérico da escala de diálogo.

*bRelativeToOrig*<br/>
Indica se o dimensionamento se aplica ao tamanho original do item do documento.

### <a name="return-value"></a>Valor retornado

Não zero se manuseado; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada. Você deve substituir esta função para ativar os controles de dimensionamento.

> [!NOTE]
> Antes de a caixa de diálogo Propriedades de objeto OLE comum ser exibida, a estrutura chama essa função com um NULL para *pItem* e a - 1 para *nCurrentScale*. Isso é feito para determinar se os controles de dimensionamento devem ser ativados.

## <a name="see-also"></a>Confira também

[MFC Amostra CIRC](../../overview/visual-cpp-samples.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Classe CPropertyPage](../../mfc/reference/cpropertypage-class.md)
