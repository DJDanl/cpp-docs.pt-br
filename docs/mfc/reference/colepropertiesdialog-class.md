---
title: Classe COlePropertiesDialog | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
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
dev_langs: C++
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
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a5460926e1f58a557b26d8e5fa0a0ed763fc5de6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="colepropertiesdialog-class"></a>Classe COlePropertiesDialog
Encapsula a caixa de diálogo de propriedades do objeto OLE comuns do Windows.  
  
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
|[COlePropertiesDialog::OnApplyScale](#onapplyscale)|Chamado pelo framework quando o dimensionamento do item do documento é alterado.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePropertiesDialog::m_gp](#m_gp)|Uma estrutura usada para inicializar a página "Geral" de um `COlePropertiesDialog` objeto.|  
|[COlePropertiesDialog::m_lp](#m_lp)|Uma estrutura usada para inicializar a página "Link" de um `COlePropertiesDialog` objeto.|  
|[COlePropertiesDialog::m_op](#m_op)|Uma estrutura usada para inicializar o `COlePropertiesDialog` objeto.|  
|[COlePropertiesDialog::m_psh](#m_psh)|Uma estrutura usada para adicionar as páginas de propriedades personalizadas adicionais.|  
|[COlePropertiesDialog::m_vp](#m_vp)|Uma estrutura usada para personalizar a página "View" de um `COlePropertiesDialog` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Caixas de diálogo de propriedades do objeto OLE comuns fornecem uma maneira fácil de exibir e modificar as propriedades de um item do documento OLE de maneira consistente com os padrões do Windows. Essas propriedades incluem, entre outras coisas, informações sobre o arquivo representado por um item do documento, opções de exibição de ícone e a escala da imagem e informações sobre o link do item (se o item está vinculado).  
  
 Para usar um `COlePropertiesDialog` de objeto, primeiro crie o objeto usando o `COlePropertiesDialog` construtor. Depois que a caixa de diálogo foi construída, chame o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário modificar as propriedades do item. `DoModal`Retorna se o usuário selecionou o Okey ( **IDOK**) ou o cancelamento ( **IDCANCEL**) botão. Além dos botões Okey e Cancelar, há um botão Aplicar. Quando o usuário seleciona aplicar, as alterações feitas nas propriedades do item de documento são aplicadas ao item e sua imagem é atualizada automaticamente, mas permanece ativa.  
  
 O [m_psh](#m_psh) membro de dados é um ponteiro para um **PROPSHEETHEADER** estrutura e na maioria dos casos, não será necessário acessá-lo explicitamente. Uma exceção é quando você precisa de páginas de propriedades adicionais além as páginas geral, a exibição e o Link de padrão. Nesse caso, você pode modificar o `m_psh` membro de dados para incluir suas páginas personalizadas antes de chamar o `DoModal` função de membro.  
  
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
  
##  <a name="colepropertiesdialog"></a>COlePropertiesDialog::COlePropertiesDialog  
 Cria um objeto `COlePropertiesDialog`.  
  
```  
COlePropertiesDialog(
    COleClientItem* pItem,  
    UINT nScaleMin = 10,  
    UINT nScaleMax = 500,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Ponteiro para o item do documento cujas propriedades estão sendo acessadas.  
  
 *nScaleMin*  
 Mínimo de escala porcentagem para a imagem de item do documento.  
  
 *nScaleMax*  
 Máximo de escala porcentagem para a imagem de item do documento.  
  
 `pParentWnd`  
 Ponteiro para o pai ou o proprietário da caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Derive sua classe de caixa de diálogo Propriedades do objeto OLE comuns da `COlePropertiesDialog` para implementar o dimensionamento de seus itens de documento. As caixas de diálogo implementadas por uma instância dessa classe não dará suporte a expansão de item do documento.  
  
 Por padrão, a caixa de diálogo Propriedades do objeto OLE comum tem três páginas padrão:  
  
-   Geral  
  
     Esta página contém informações do sistema para o arquivo representado por um item do documento selecionado. Nessa página, o usuário pode converter o item selecionado em outro tipo.  
  
-   Exibir  
  
     Essa página contém opções para exibir o item, alterando o ícone e alteração do dimensionamento da imagem.  
  
-   Link  
  
     Essa página contém opções para alterar o local do item vinculado e atualizar o item vinculado. Nessa página, o usuário pode quebrar o link do item selecionado.  
  
 Para adicionar páginas além daquelas fornecidas por padrão, modifique o [m_psh](#m_psh) variável de membro antes de sair do construtor de seu `COlePropertiesDialog`-classe derivada. Esta é uma implementação avançada do `COlePropertiesDialog` construtor.  
  
##  <a name="domodal"></a>COlePropertiesDialog::DoModal  
 Chame essa função de membro para exibir a caixa de diálogo de propriedades do objeto OLE comuns do Windows e permitir que o usuário exibir e/ou alterar as propriedades do item do documento.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **IDOK** ou **IDCANCEL** se bem-sucedido; caso contrário, 0. **IDOK** e **IDCANCEL** são constantes que indicam se o usuário selecionou o botão Okey ou em Cancelar.  
  
 Se **IDCANCEL** for retornado, você pode chamar o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro.  
  
##  <a name="m_gp"></a>COlePropertiesDialog::m_gp  
 Uma estrutura de tipo [OLEUIGNRLPROPS](http://msdn.microsoft.com/library/windows/desktop/ms687297), usado para inicializar a página geral da caixa de diálogo Propriedades do objeto OLE.  
  
```  
OLEUIGNRLPROPS m_gp;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta página mostra o tipo e tamanho de uma inserção e permite que o usuário acesse a caixa de diálogo Converter. Essa página também mostra o destino do link se o objeto é um link.  
  
 Para obter mais informações sobre o **OLEUIGNRLPROPS** estrutura, consulte o SDK do Windows.  
  
##  <a name="m_lp"></a>COlePropertiesDialog::m_lp  
 Uma estrutura de tipo [OLEUILINKPROPS](http://msdn.microsoft.com/library/windows/desktop/ms680735), usado para inicializar a página de Link da caixa de diálogo Propriedades do objeto OLE.  
  
```  
OLEUILINKPROPS m_lp;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta página mostra o local do item vinculado e permite que o usuário atualizar ou interromper o link para o item.  
  
 Para obter mais informações sobre o **OLEUILINKPROPS** estrutura, consulte o SDK do Windows.  
  
##  <a name="m_op"></a>COlePropertiesDialog::m_op  
 Uma estrutura de tipo [OLEUIOBJECTPROPS](http://msdn.microsoft.com/library/windows/desktop/ms687199), usado para inicializar a caixa de diálogo Propriedades do objeto OLE comuns.  
  
```  
OLEUIOBJECTPROPS m_op;  
```  
  
### <a name="remarks"></a>Comentários  
 Essa estrutura contém membros usados para inicializar as páginas geral, o Link e o modo de exibição.  
  
 Para obter mais informações, consulte o **OLEUIOBJECTPROPS** e [OLEUILINKPROPS](http://msdn.microsoft.com/library/windows/desktop/ms680735) estruturas no SDK do Windows.  
  
##  <a name="m_psh"></a>COlePropertiesDialog::m_psh  
 Uma estrutura de tipo [PROPSHEETHEADER](http://msdn.microsoft.com/library/windows/desktop/bb774546), cujos membros armazenam as características do objeto de caixa de diálogo.  
  
```  
PROPSHEETHEADER m_psh;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de construir um `COlePropertiesDialog` do objeto, você pode usar `m_psh` para definir vários aspectos da caixa de diálogo antes de chamar o `DoModal` função de membro.  
  
 Se você modificar o `m_psh` membro de dados diretamente, você substituirá qualquer comportamento padrão.  
  
 Para obter mais informações sobre o **PROPSHEETHEADER** estrutura, consulte o SDK do Windows.  
  
##  <a name="m_vp"></a>COlePropertiesDialog::m_vp  
 Uma estrutura de tipo [OLEUIVIEWPROPS](http://msdn.microsoft.com/library/windows/desktop/ms693751), usado para inicializar a página de exibição da caixa de diálogo Propriedades do objeto OLE.  
  
```  
OLEUIVIEWPROPS m_vp;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta página permite que o usuário alterne entre "conteúdo" e "ícones" modos de exibição do objeto e altere sua escala dentro do contêiner. Ele também permite o acesso do usuário à caixa de diálogo Alterar ícone quando o objeto está sendo exibido como um ícone.  
  
 Para obter mais informações sobre o **OLEUIVIEWPROPS** estrutura, consulte o SDK do Windows.  
  
##  <a name="onapplyscale"></a>COlePropertiesDialog::OnApplyScale  
 Chamado pelo framework quando o valor de escala foi alterada e Okey ou aplicar foi selecionado.  
  
```  
virtual BOOL OnApplyScale(
    COleClientItem* pItem,  
    int nCurrentScale,  
    BOOL bRelativeToOrig);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Ponteiro para o item do documento cujas propriedades estão sendo acessadas.  
  
 `nCurrentScale`  
 Valor numérico da escala de caixa de diálogo.  
  
 *bRelativeToOrig*  
 Indica se dimensionamento aplica-se ao tamanho original do item do documento.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se tratadas; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não fará nada. Você deve substituir esta função para habilitar os controles de dimensionamento.  
  
> [!NOTE]
>  Antes que seja exibida a caixa de diálogo Propriedades do objeto OLE comum, o framework chama essa função com um **nulo** para `pItem` e -1 para `nCurrentScale`. Isso é feito para determinar se os controles de dimensionamento devem ser habilitados.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC c](../../visual-cpp-samples.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Classe CPropertyPage](../../mfc/reference/cpropertypage-class.md)
