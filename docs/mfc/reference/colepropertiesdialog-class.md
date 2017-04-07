---
title: Classe COlePropertiesDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
dev_langs:
- C++
helpviewer_keywords:
- OLE Object Properties dialog box
- Object Properties dialog box
- dialog boxes, OLE
- OLE documents, modifying properties
- property pages, OLE
- COlePropertiesDialog class
ms.assetid: a54dbc89-1447-4329-bd01-00e98ec9e935
caps.latest.revision: 23
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 0c07766bca6bbc546f877e10255d80bd388d30d7
ms.lasthandoff: 02/25/2017

---
# <a name="colepropertiesdialog-class"></a>Classe COlePropertiesDialog
Encapsula a caixa de diálogo de propriedades do objeto OLE comuns do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COlePropertiesDialog : public COleDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePropertiesDialog::COlePropertiesDialog](#colepropertiesdialog)|Constrói um objeto `COlePropertiesDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePropertiesDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|  
|[COlePropertiesDialog::OnApplyScale](#onapplyscale)|Chamado pela estrutura quando o dimensionamento do item de documento é alterado.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePropertiesDialog::m_gp](#m_gp)|Uma estrutura usada para inicializar a página "Geral" de um `COlePropertiesDialog` objeto.|  
|[COlePropertiesDialog::m_lp](#m_lp)|Uma estrutura usada para inicializar a página "Link" de uma `COlePropertiesDialog` objeto.|  
|[COlePropertiesDialog::m_op](#m_op)|Uma estrutura usada para inicializar o `COlePropertiesDialog` objeto.|  
|[COlePropertiesDialog::m_psh](#m_psh)|Uma estrutura usada para adicionar páginas de propriedades personalizadas adicionais.|  
|[COlePropertiesDialog::m_vp](#m_vp)|Uma estrutura usada para personalizar a página de "Exibição" de uma `COlePropertiesDialog` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Caixas de diálogo de propriedades do objeto OLE comuns fornecem uma maneira fácil de exibir e modificar as propriedades de um item de documento OLE de maneira consistente com os padrões do Windows. Essas propriedades incluem, entre outros, informações sobre o arquivo representado pelo item de documento, as opções para exibir o ícone e a escala da imagem e informações sobre o link do item (se o item está vinculado).  
  
 Para usar um `COlePropertiesDialog` de objeto, primeiro crie o objeto usando o `COlePropertiesDialog` construtor. Depois que a caixa de diálogo foi construída, chame o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário modifique as propriedades do item. `DoModal`Retorna se o usuário selecionou o Okey ( **IDOK**) ou a cancelar ( **IDCANCEL**) botão. Além dos botões Okey e Cancelar, há um botão Aplicar. Quando o usuário seleciona aplicar, todas as alterações feitas nas propriedades do item de documento são aplicadas ao item e a imagem é atualizada automaticamente, mas permanece ativa.  
  
 O [m_psh](#m_psh) membro de dados é um ponteiro para um **PROPSHEETHEADER** estrutura e na maioria dos casos, não será necessário acessá-lo explicitamente. Uma exceção é quando você precisa de páginas de propriedades adicionais além das páginas padrão de gerais, de modo de exibição e Link. Nesse caso, você pode modificar o `m_psh` membro de dados para incluir suas páginas personalizadas antes de chamar o `DoModal` função de membro.  
  
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
 Ponteiro para o item de documento cujas propriedades estão sendo acessadas.  
  
 *nScaleMin*  
 Mínimo de escala porcentagem para a imagem de item de documento.  
  
 *nScaleMax*  
 Máximo de escala porcentagem para a imagem de item de documento.  
  
 `pParentWnd`  
 Ponteiro para o pai ou o proprietário da caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Derive sua classe de caixa de diálogo Propriedades do objeto OLE comuns da `COlePropertiesDialog` para implementar o dimensionamento de seus itens de documento. As caixas de diálogo implementadas por uma instância dessa classe não oferecerá suporte a dimensionamento do item de documento.  
  
 Por padrão, a caixa de diálogo Propriedades do objeto OLE comum tem três páginas padrão:  
  
-   Geral  
  
     Esta página contém informações do sistema para o arquivo representado pelo item de documento selecionado. Nessa página, o usuário pode converter o item selecionado em outro tipo.  
  
-   Exibir  
  
     Esta página contém opções para exibir o item, alterando o ícone e alterar a escala da imagem.  
  
-   Link  
  
     Esta página contém opções para alterar o local do item vinculado e atualizar o item vinculado. Nessa página, o usuário pode quebrar o vínculo do item selecionado.  
  
 Para adicionar páginas além daqueles fornecidos por padrão, modifique o [m_psh](#m_psh) variável de membro antes de sair do construtor da sua `COlePropertiesDialog`-classe derivada. Esta é uma implementação avançada do `COlePropertiesDialog` construtor.  
  
##  <a name="domodal"></a>COlePropertiesDialog::DoModal  
 Chame essa função de membro para exibir a caixa de diálogo de propriedades do objeto OLE comuns do Windows e permitir que o usuário exibir e/ou alterar as propriedades do item de documento.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **IDOK** ou **IDCANCEL** se bem-sucedido; caso contrário, 0. **IDOK** e **IDCANCEL** são constantes que indicam se o usuário selecionou o botão Okey ou Cancelar.  
  
 Se **IDCANCEL** for retornado, você pode chamar o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro.  
  
##  <a name="m_gp"></a>COlePropertiesDialog::m_gp  
 Uma estrutura do tipo [OLEUIGNRLPROPS](http://msdn.microsoft.com/library/windows/desktop/ms687297), usado para inicializar a página geral da caixa de diálogo Propriedades do objeto OLE.  
  
```  
OLEUIGNRLPROPS m_gp;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta página mostra o tipo e o tamanho de uma inserção e permite ao usuário acesso à caixa de diálogo Converter. Esta página também mostra o destino do link se o objeto é um link.  
  
 Para obter mais informações sobre o **OLEUIGNRLPROPS** estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="m_lp"></a>COlePropertiesDialog::m_lp  
 Uma estrutura do tipo [OLEUILINKPROPS](http://msdn.microsoft.com/library/windows/desktop/ms680735), usado para inicializar a página de Link da caixa de diálogo Propriedades do objeto OLE.  
  
```  
OLEUILINKPROPS m_lp;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta página mostra o local do item vinculado e permite ao usuário atualizar ou interromper o link para o item.  
  
 Para obter mais informações sobre o **OLEUILINKPROPS** estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="m_op"></a>COlePropertiesDialog::m_op  
 Uma estrutura do tipo [OLEUIOBJECTPROPS](http://msdn.microsoft.com/library/windows/desktop/ms687199), usado para inicializar a caixa de diálogo Propriedades do objeto OLE comuns.  
  
```  
OLEUIOBJECTPROPS m_op;  
```  
  
### <a name="remarks"></a>Comentários  
 Essa estrutura contém membros usados para inicializar as páginas geral, links e exibição.  
  
 Para obter mais informações, consulte o **OLEUIOBJECTPROPS** e [OLEUILINKPROPS](http://msdn.microsoft.com/library/windows/desktop/ms680735) estruturas no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="m_psh"></a>COlePropertiesDialog::m_psh  
 Uma estrutura do tipo [PROPSHEETHEADER](http://msdn.microsoft.com/library/windows/desktop/bb774546), cujos membros armazenam as características do objeto de caixa de diálogo.  
  
```  
PROPSHEETHEADER m_psh;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar um `COlePropertiesDialog` do objeto, você pode usar `m_psh` para definir vários aspectos da caixa de diálogo antes de chamar o `DoModal` função de membro.  
  
 Se você modificar o `m_psh` membro de dados diretamente, você substituirá qualquer comportamento padrão.  
  
 Para obter mais informações sobre o **PROPSHEETHEADER** estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="m_vp"></a>COlePropertiesDialog::m_vp  
 Uma estrutura do tipo [OLEUIVIEWPROPS](http://msdn.microsoft.com/library/windows/desktop/ms693751), usado para inicializar a página de exibição da caixa de diálogo Propriedades do objeto OLE.  
  
```  
OLEUIVIEWPROPS m_vp;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta página permite ao usuário alternar entre "conteúdo" e "icônico" modos de exibição do objeto e alterar sua escala dentro do contêiner. Ele também permite ao usuário acesso à caixa de diálogo Alterar ícone quando o objeto está sendo exibido como um ícone.  
  
 Para obter mais informações sobre o **OLEUIVIEWPROPS** estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onapplyscale"></a>COlePropertiesDialog::OnApplyScale  
 Chamado pela estrutura quando o valor de escala foi alterada e Okey ou aplicar foi selecionado.  
  
```  
virtual BOOL OnApplyScale(
    COleClientItem* pItem,  
    int nCurrentScale,  
    BOOL bRelativeToOrig);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Ponteiro para o item de documento cujas propriedades estão sendo acessadas.  
  
 `nCurrentScale`  
 Valor numérico da escala de caixa de diálogo.  
  
 *bRelativeToOrig*  
 Indica se o dimensionamento aplica-se ao tamanho original do item de documento.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se tratadas; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada. Você deve substituir essa função para habilitar os controles de dimensionamento.  
  
> [!NOTE]
>  Antes que seja exibida a caixa de diálogo Propriedades do objeto OLE comum, a estrutura chama essa função com uma **nulo** para `pItem` e – 1 para `nCurrentScale`. Isso é feito para determinar se os controles de dimensionamento devem ser habilitados.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC c](../../visual-cpp-samples.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Classe CPropertyPage](../../mfc/reference/cpropertypage-class.md)

