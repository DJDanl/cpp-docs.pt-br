---
title: Classe COlePropertiesDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5c32aed9d50e0575893c99a9552c74e6e491ecb9
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37853014"
---
# <a name="colepropertiesdialog-class"></a>Classe COlePropertiesDialog
Encapsula a caixa de diálogo de propriedades do objeto OLE comum do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COlePropertiesDialog : public COleDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePropertiesDialog::COlePropertiesDialog](#colepropertiesdialog)|Constrói um objeto `COlePropertiesDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePropertiesDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|  
|[COlePropertiesDialog::OnApplyScale](#onapplyscale)|Chamado pelo framework quando o dimensionamento do item de documento é alterado.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePropertiesDialog::m_gp](#m_gp)|Uma estrutura usada para inicializar a página "Geral" de um `COlePropertiesDialog` objeto.|  
|[COlePropertiesDialog::m_lp](#m_lp)|Uma estrutura usada para inicializar a página de "Link" de um `COlePropertiesDialog` objeto.|  
|[COlePropertiesDialog::m_op](#m_op)|Uma estrutura usada para inicializar o `COlePropertiesDialog` objeto.|  
|[COlePropertiesDialog::m_psh](#m_psh)|Uma estrutura usada para adicionar páginas de propriedades personalizadas adicionais.|  
|[COlePropertiesDialog::m_vp](#m_vp)|Uma estrutura usada para personalizar a página de "View" de um `COlePropertiesDialog` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Caixas de diálogo de propriedades do objeto OLE comuns fornecem uma maneira fácil de exibir e modificar as propriedades de um item de documento OLE de maneira consistente com os padrões do Windows. Essas propriedades incluem, entre outros, informações sobre o arquivo representado pelo item de documento, as opções para exibir o ícone e a escala da imagem e informações sobre o link do item (se o item está vinculado).  
  
 Para usar um `COlePropertiesDialog` do objeto, primeiro crie o objeto usando o `COlePropertiesDialog` construtor. Depois que a caixa de diálogo foi construída, chame o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário modificar as propriedades do item. `DoModal` Retorna se o usuário selecionou Okey (IDOK) ou o botão Cancelar (IDCANCEL). Além dos botões Okey e Cancelar, há um botão Aplicar. Quando o usuário seleciona a aplicar, quaisquer alterações feitas nas propriedades do item de documento são aplicadas ao item e sua imagem é atualizada automaticamente, mas permanece ativa.  
  
 O [m_psh](#m_psh) membro de dados é um ponteiro para um `PROPSHEETHEADER` estrutura, na maioria dos casos, você não precisará acessá-lo explicitamente. Uma exceção é quando você precisar de páginas de propriedades adicionais além das páginas geral, o modo de exibição e o Link do padrão. Nesse caso, você pode modificar os `m_psh` membro de dados para incluir suas páginas personalizadas antes de chamar o `DoModal` função de membro.  
  
 Para obter mais informações sobre caixas de diálogo OLE, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COlePropertiesDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
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
 *pItem*  
 Ponteiro para o item do documento cujas propriedades estão sendo acessadas.  
  
 *nScaleMin*  
 Mínimo de porcentagem para a imagem de item de documento de dimensionamento.  
  
 *nScaleMax*  
 Máximo de escala porcentagem para a imagem de item de documento.  
  
 *pParentWnd*  
 Ponteiro para a caixa de diálogo pai ou proprietária.  
  
### <a name="remarks"></a>Comentários  
 Derive sua classe de caixa de diálogo Propriedades do objeto OLE comum do `COlePropertiesDialog` para implementar a colocação em escala para seus itens de documento. Todas as caixas de diálogo implementadas por uma instância dessa classe não dará suporte a dimensionamento do item do documento.  
  
 Por padrão, a caixa de diálogo Propriedades do objeto OLE comum tem três páginas padrão:  
  
-   Geral  
  
     Esta página contém informações do sistema para o arquivo representado pelo item de documento selecionado. Nessa página, o usuário pode converter o item selecionado em outro tipo.  
  
-   Exibir  
  
     Esta página contém opções para exibir o item, alterando o ícone e alteração do dimensionamento da imagem.  
  
-   Link  
  
     Esta página contém as opções para alterar o local do item vinculado e atualizar o item vinculado. Nessa página, o usuário pode desfazer o link do item selecionado.  
  
 Para adicionar páginas além daqueles fornecidos por padrão, modifique a [m_psh](#m_psh) variável de membro antes de sair do construtor da sua `COlePropertiesDialog`-classe derivada. Essa é uma implementação avançada do `COlePropertiesDialog` construtor.  
  
##  <a name="domodal"></a>  COlePropertiesDialog::DoModal  
 Chame essa função de membro para exibir a caixa de diálogo de propriedades do objeto OLE comum do Windows e permitir que o usuário exibir e/ou alterar as propriedades do item de documento.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 IDOK ou IDCANCEL se bem-sucedido; Caso contrário, 0. IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão Okey ou em Cancelar.  
  
 Se IDCANCEL for retornado, você pode chamar o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro.  
  
##  <a name="m_gp"></a>  COlePropertiesDialog::m_gp  
 Uma estrutura do tipo [OLEUIGNRLPROPS](http://msdn.microsoft.com/library/windows/desktop/ms687297), usado para inicializar a página geral da caixa de diálogo Propriedades do objeto OLE.  
  
```  
OLEUIGNRLPROPS m_gp;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta página mostra o tipo e tamanho de uma inserção e permite que o usuário acesse a caixa de diálogo Converter. Esta página também mostra o destino do link se o objeto é um link.  
  
 Para obter mais informações sobre o `OLEUIGNRLPROPS` estrutura, consulte o SDK do Windows.  
  
##  <a name="m_lp"></a>  COlePropertiesDialog::m_lp  
 Uma estrutura do tipo [OLEUILINKPROPS](http://msdn.microsoft.com/library/windows/desktop/ms680735), usado para inicializar a página de Link da caixa de diálogo Propriedades do objeto OLE.  
  
```  
OLEUILINKPROPS m_lp;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta página mostra o local do item vinculado e permite que o usuário atualize ou uma interrupção, o link para o item.  
  
 Para obter mais informações sobre o `OLEUILINKPROPS` estrutura, consulte o SDK do Windows.  
  
##  <a name="m_op"></a>  COlePropertiesDialog::m_op  
 Uma estrutura do tipo [OLEUIOBJECTPROPS](http://msdn.microsoft.com/library/windows/desktop/ms687199), usado para inicializar a caixa de diálogo Propriedades do objeto OLE comum.  
  
```  
OLEUIOBJECTPROPS m_op;  
```  
  
### <a name="remarks"></a>Comentários  
 Essa estrutura contém membros usados para inicializar as páginas geral, o Link e o modo de exibição.  
  
 Para obter mais informações, consulte o OLEUIOBJECTPROPS e [OLEUILINKPROPS](http://msdn.microsoft.com/library/windows/desktop/ms680735) estruturas no SDK do Windows.  
  
##  <a name="m_psh"></a>  COlePropertiesDialog::m_psh  
 Uma estrutura do tipo [PROPSHEETHEADER](http://msdn.microsoft.com/library/windows/desktop/bb774546), cujos membros armazenam as características do objeto de caixa de diálogo.  
  
```  
PROPSHEETHEADER m_psh;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar uma `COlePropertiesDialog` objeto, você pode usar `m_psh` para definir vários aspectos da caixa de diálogo antes de chamar o `DoModal` função de membro.  
  
 Se você modificar o `m_psh` membro de dados diretamente, você substituirá qualquer comportamento padrão.  
  
 Para obter mais informações sobre o `PROPSHEETHEADER` estrutura, consulte o SDK do Windows.  
  
##  <a name="m_vp"></a>  COlePropertiesDialog::m_vp  
 Uma estrutura do tipo [OLEUIVIEWPROPS](http://msdn.microsoft.com/library/windows/desktop/ms693751), usado para inicializar a página de exibição da caixa de diálogo Propriedades do objeto OLE.  
  
```  
OLEUIVIEWPROPS m_vp;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta página permite que o usuário alterne entre "conteúdo" e "icônico" modos de exibição do objeto e alterar sua colocação em escala dentro do contêiner. Ele também permite ao usuário acesso à caixa de diálogo Alterar ícone quando o objeto está sendo exibido como um ícone.  
  
 Para obter mais informações sobre o `OLEUIVIEWPROPS` estrutura, consulte o SDK do Windows.  
  
##  <a name="onapplyscale"></a>  COlePropertiesDialog::OnApplyScale  
 Chamado pelo framework quando o valor de escala foi alterado e Okey ou aplicar foi selecionado.  
  
```  
virtual BOOL OnApplyScale(
    COleClientItem* pItem,  
    int nCurrentScale,  
    BOOL bRelativeToOrig);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pItem*  
 Ponteiro para o item do documento cujas propriedades estão sendo acessadas.  
  
 *nCurrentScale*  
 Valor numérico de escala a caixa de diálogo.  
  
 *bRelativeToOrig*  
 Indica se o dimensionamento se aplica ao tamanho original do item de documento.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se tratado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada. Você deve substituir essa função para habilitar os controles de colocação em escala.  
  
> [!NOTE]
>  Antes que seja exibida a caixa de diálogo Propriedades do objeto OLE comum, o framework chama essa função com um valor NULL para *pItem* e a - 1 para *nCurrentScale*. Isso é feito para determinar se os controles de dimensionamento devem ser habilitados.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC c](../../visual-cpp-samples.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Classe CPropertyPage](../../mfc/reference/cpropertypage-class.md)
