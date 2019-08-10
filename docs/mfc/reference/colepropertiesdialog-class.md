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
ms.openlocfilehash: bdae64ff4a7bcfef761eaf3dd70a85a54efc28b7
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68916953"
---
# <a name="colepropertiesdialog-class"></a>Classe COlePropertiesDialog

Encapsula a caixa de diálogo Propriedades do objeto OLE comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class COlePropertiesDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COlePropertiesDialog::COlePropertiesDialog](#colepropertiesdialog)|Constrói um objeto `COlePropertiesDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COlePropertiesDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|
|[COlePropertiesDialog::OnApplyScale](#onapplyscale)|Chamado pelo Framework quando o dimensionamento do item do documento é alterado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COlePropertiesDialog::m_gp](#m_gp)|Uma estrutura usada para inicializar a página "geral" de um `COlePropertiesDialog` objeto.|
|[COlePropertiesDialog::m_lp](#m_lp)|Uma estrutura usada para inicializar a página "link" de um `COlePropertiesDialog` objeto.|
|[COlePropertiesDialog::m_op](#m_op)|Uma estrutura usada para inicializar o `COlePropertiesDialog` objeto.|
|[COlePropertiesDialog::m_psh](#m_psh)|Uma estrutura usada para adicionar outras páginas de propriedades personalizadas.|
|[COlePropertiesDialog::m_vp](#m_vp)|Uma estrutura usada para personalizar a página de "exibição" de `COlePropertiesDialog` um objeto.|

## <a name="remarks"></a>Comentários

As caixas de diálogo comuns de objeto OLE fornecem uma maneira fácil de exibir e modificar as propriedades de um item de documento OLE de maneira consistente com os padrões do Windows. Essas propriedades incluem, entre outras, informações sobre o arquivo representado pelo item de documento, opções para exibir o ícone e o dimensionamento da imagem e informações sobre o link do item (se o item estiver vinculado).

Para usar um `COlePropertiesDialog` objeto, primeiro crie o objeto usando o `COlePropertiesDialog` Construtor. Após a construção da caixa de diálogo, chame a `DoModal` função Member para exibir a caixa de diálogo e permitir que o usuário modifique as propriedades do item. `DoModal`Retorna se o usuário selecionou o botão OK (IDOK) ou Cancel (IDCANCEL). Além dos botões OK e cancelar, há um botão Aplicar. Quando o usuário seleciona aplicar, todas as alterações feitas nas propriedades do item de documento são aplicadas ao item e sua imagem é atualizada automaticamente, mas permanece ativa.

O membro de dados [m_psh](#m_psh) é um ponteiro para `PROPSHEETHEADER` uma estrutura e, na maioria dos casos, não será necessário acessá-lo explicitamente. Uma exceção é quando você precisa de páginas de propriedades adicionais além das páginas padrão geral, exibição e link. Nesse caso, você pode modificar o `m_psh` membro de dados para incluir suas páginas personalizadas antes de chamar a função de `DoModal` membro.

Para obter mais informações sobre caixas de diálogo OLE, consulte as caixas de diálogo do artigo [em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

[COleDialog](../../mfc/reference/coledialog-class.md)

`COlePropertiesDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs. h

##  <a name="colepropertiesdialog"></a>  COlePropertiesDialog::COlePropertiesDialog

Cria um objeto `COlePropertiesDialog`.

```
COlePropertiesDialog(
    COleClientItem* pItem,
    UINT nScaleMin = 10,
    UINT nScaleMax = 500,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Ponteiro para o item de documento cujas propriedades estão sendo acessadas.

*nScaleMin*<br/>
Porcentagem de dimensionamento mínima para a imagem do item de documento.

*nScaleMax*<br/>
Porcentagem máxima de dimensionamento para a imagem do item de documento.

*pParentWnd*<br/>
Ponteiro para o pai ou proprietário da caixa de diálogo.

### <a name="remarks"></a>Comentários

Derive sua classe de caixa de diálogo comum `COlePropertiesDialog` de propriedades OLE Object a fim de implementar o dimensionamento para seus itens de documento. Qualquer caixa de diálogo implementada por uma instância dessa classe não dará suporte ao dimensionamento do item de documento.

Por padrão, a caixa de diálogo Propriedades comuns do objeto OLE tem três páginas padrão:

- Geral

   Esta página contém informações do sistema para o arquivo representado pelo item de documento selecionado. Nessa página, o usuário pode converter o item selecionado em outro tipo.

- Exibir

   Esta página contém opções para exibir o item, alterar o ícone e alterar o dimensionamento da imagem.

- Link

   Esta página contém opções para alterar o local do item vinculado e atualizar o item vinculado. Nessa página, o usuário pode quebrar o link do item selecionado.

Para adicionar páginas além daquelas fornecidas por padrão, modifique a variável de membro [m_psh](#m_psh) antes de sair do construtor `COlePropertiesDialog`de sua classe derivada. Esta é uma implementação avançada do `COlePropertiesDialog` Construtor.

##  <a name="domodal"></a>COlePropertiesDialog::D oModal

Chame essa função de membro para exibir a caixa de diálogo Propriedades do objeto OLE comum do Windows e permitir que o usuário exiba e/ou altere as várias propriedades do item de documento.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

IDOK ou IDCANCEL se for bem-sucedido; caso contrário, 0. IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão OK ou cancelar.

Se IDCANCEL for retornado, você poderá chamar a função [CommDlgExtendedError](/windows/desktop/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro.

##  <a name="m_gp"></a>  COlePropertiesDialog::m_gp

Uma estrutura do tipo [OLEUIGNRLPROPS](/windows/desktop/api/oledlg/ns-oledlg-tagoleuignrlpropsa), usada para inicializar a página Geral da caixa de diálogo Propriedades do objeto OLE.

```
OLEUIGNRLPROPS m_gp;
```

### <a name="remarks"></a>Comentários

Esta página mostra o tipo e o tamanho de uma incorporação e permite que o usuário acesse a caixa de diálogo Converter. Essa página também mostrará o destino do link se o objeto for um link.

Para obter mais informações sobre `OLEUIGNRLPROPS` a estrutura, consulte a SDK do Windows.

##  <a name="m_lp"></a>  COlePropertiesDialog::m_lp

Uma estrutura do tipo [OLEUILINKPROPS](/windows/desktop/api/oledlg/ns-oledlg-tagoleuilinkpropsa), usada para inicializar a página de link da caixa de diálogo Propriedades do objeto OLE.

```
OLEUILINKPROPS m_lp;
```

### <a name="remarks"></a>Comentários

Esta página mostra o local do item vinculado e permite que o usuário atualize ou quebre o link para o item.

Para obter mais informações sobre `OLEUILINKPROPS` a estrutura, consulte a SDK do Windows.

##  <a name="m_op"></a>  COlePropertiesDialog::m_op

Uma estrutura do tipo [OLEUIOBJECTPROPS](/windows/desktop/api/oledlg/ns-oledlg-tagoleuiobjectpropsa), usada para inicializar a caixa de diálogo Propriedades comuns do objeto OLE.

```
OLEUIOBJECTPROPS m_op;
```

### <a name="remarks"></a>Comentários

Essa estrutura contém membros usados para inicializar as páginas geral, link e exibição.

Para obter mais informações, consulte as estruturas OLEUIOBJECTPROPS e [OLEUILINKPROPS](/windows/desktop/api/oledlg/ns-oledlg-tagoleuilinkpropsa) no SDK do Windows.

##  <a name="m_psh"></a>  COlePropertiesDialog::m_psh

Uma estrutura do tipo [PROPSHEETHEADER](/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2), cujos membros armazenam as características do objeto da caixa de diálogo.

```
PROPSHEETHEADER m_psh;
```

### <a name="remarks"></a>Comentários

Depois de construir um `COlePropertiesDialog` objeto, você pode usar `m_psh` para definir vários aspectos da caixa de diálogo antes de chamar `DoModal` a função de membro.

Se você modificar o `m_psh` membro de dados diretamente, substituirá qualquer comportamento padrão.

Para obter mais informações sobre `PROPSHEETHEADER` a estrutura, consulte a SDK do Windows.

##  <a name="m_vp"></a>  COlePropertiesDialog::m_vp

Uma estrutura do tipo [OLEUIVIEWPROPS](/windows/desktop/api/oledlg/ns-oledlg-tagoleuiviewpropsa), usada para inicializar a página de exibição da caixa de diálogo Propriedades do objeto OLE.

```
OLEUIVIEWPROPS m_vp;
```

### <a name="remarks"></a>Comentários

Esta página permite que o usuário alterne entre as exibições "conteúdo" e "icônico" do objeto e altere seu dimensionamento dentro do contêiner. Ele também permite que o usuário acesse a caixa de diálogo Alterar ícone quando o objeto está sendo exibido como um ícone.

Para obter mais informações sobre `OLEUIVIEWPROPS` a estrutura, consulte a SDK do Windows.

##  <a name="onapplyscale"></a>  COlePropertiesDialog::OnApplyScale

Chamado pelo Framework quando o valor de dimensionamento foi alterado e OK ou aplicar foi selecionado.

```
virtual BOOL OnApplyScale(
    COleClientItem* pItem,
    int nCurrentScale,
    BOOL bRelativeToOrig);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Ponteiro para o item de documento cujas propriedades estão sendo acessadas.

*nCurrentScale*<br/>
Valor numérico da escala da caixa de diálogo.

*bRelativeToOrig*<br/>
Indica se o dimensionamento se aplica ao tamanho original do item do documento.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for manipulado; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada. Você deve substituir essa função para habilitar os controles de dimensionamento.

> [!NOTE]
>  Antes que a caixa de diálogo Propriedades comuns do objeto OLE seja exibida, a estrutura chama essa função com um NULL para *pItem* e um-1 para *nCurrentScale*. Isso é feito para determinar se os controles de dimensionamento devem ser habilitados.

## <a name="see-also"></a>Consulte também

[Exemplo CIRC do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Classe CPropertyPage](../../mfc/reference/cpropertypage-class.md)
