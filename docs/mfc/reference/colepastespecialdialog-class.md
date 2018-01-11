---
title: Classe COlePasteSpecialDialog | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COlePasteSpecialDialog
- AFXODLGS/COlePasteSpecialDialog
- AFXODLGS/COlePasteSpecialDialog::COlePasteSpecialDialog
- AFXODLGS/COlePasteSpecialDialog::AddFormat
- AFXODLGS/COlePasteSpecialDialog::AddLinkEntry
- AFXODLGS/COlePasteSpecialDialog::AddStandardFormats
- AFXODLGS/COlePasteSpecialDialog::CreateItem
- AFXODLGS/COlePasteSpecialDialog::DoModal
- AFXODLGS/COlePasteSpecialDialog::GetDrawAspect
- AFXODLGS/COlePasteSpecialDialog::GetIconicMetafile
- AFXODLGS/COlePasteSpecialDialog::GetPasteIndex
- AFXODLGS/COlePasteSpecialDialog::GetSelectionType
- AFXODLGS/COlePasteSpecialDialog::m_ps
dev_langs: C++
helpviewer_keywords:
- COlePasteSpecialDialog [MFC], COlePasteSpecialDialog
- COlePasteSpecialDialog [MFC], AddFormat
- COlePasteSpecialDialog [MFC], AddLinkEntry
- COlePasteSpecialDialog [MFC], AddStandardFormats
- COlePasteSpecialDialog [MFC], CreateItem
- COlePasteSpecialDialog [MFC], DoModal
- COlePasteSpecialDialog [MFC], GetDrawAspect
- COlePasteSpecialDialog [MFC], GetIconicMetafile
- COlePasteSpecialDialog [MFC], GetPasteIndex
- COlePasteSpecialDialog [MFC], GetSelectionType
- COlePasteSpecialDialog [MFC], m_ps
ms.assetid: 0e82ef9a-9bbe-457e-8240-42c86a0534f7
caps.latest.revision: "24"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8680842f0aeeebf98eabc0f278089781290ad902
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="colepastespecialdialog-class"></a>Classe COlePasteSpecialDialog
Usado para a caixa de diálogo OLE Colar especial.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COlePasteSpecialDialog : public COleDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePasteSpecialDialog::COlePasteSpecialDialog](#colepastespecialdialog)|Constrói um objeto `COlePasteSpecialDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePasteSpecialDialog::AddFormat](#addformat)|Adiciona formatos personalizados à lista de formatos de que seu aplicativo pode colar.|  
|[COlePasteSpecialDialog::AddLinkEntry](#addlinkentry)|Adiciona uma nova entrada à lista de formatos com suporte de área de transferência.|  
|[COlePasteSpecialDialog::AddStandardFormats](#addstandardformats)|Adiciona **CF_BITMAP**, **CF_DIB**, `CF_METAFILEPICT`e, opcionalmente, `CF_LINKSOURCE` à lista de formatos de seu aplicativo pode colar.|  
|[COlePasteSpecialDialog::CreateItem](#createitem)|Cria o item no documento contêiner usando o formato especificado.|  
|[COlePasteSpecialDialog::DoModal](#domodal)|Exibe a caixa de diálogo OLE Colar especial.|  
|[COlePasteSpecialDialog::GetDrawAspect](#getdrawaspect)|Indica se será desenhado item como um ícone ou não.|  
|[COlePasteSpecialDialog::GetIconicMetafile](#geticonicmetafile)|Obtém um identificador para o metarquivo associado ao ícone formulário deste item.|  
|[COlePasteSpecialDialog::GetPasteIndex](#getpasteindex)|Obtém o índice de opções de colagem disponíveis que foi escolhido pelo usuário.|  
|[COlePasteSpecialDialog::GetSelectionType](#getselectiontype)|Obtém o tipo de seleção escolhida.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePasteSpecialDialog::m_ps](#m_ps)|Uma estrutura de tipo **OLEUIPASTESPECIAL** que controla a função da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Criar um objeto da classe `COlePasteSpecialDialog` quando você deseja chamar essa caixa de diálogo. Após um `COlePasteSpecialDialog` objeto foi construído, você pode usar o [AddFormat](#addformat) e [AddStandardFormats](#addstandardformats) funções de membro para adicionar os formatos da área de transferência para a caixa de diálogo. Você também pode usar o [m_ps](#m_ps) estrutura para inicializar os valores ou os estados de controles da caixa de diálogo. O `m_ps` estrutura é do tipo **OLEUIPASTESPECIAL**.  
  
 Para obter mais informações, consulte o [OLEUIPASTESPECIAL](http://msdn.microsoft.com/library/windows/desktop/ms692434) estrutura no SDK do Windows.  
  
 Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COlePasteSpecialDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
##  <a name="addformat"></a>COlePasteSpecialDialog::AddFormat  
 Chame essa função para adicionar novos formatos à lista de formatos de que seu aplicativo pode dar suporte em uma operação de colar especial.  
  
```  
void AddFormat(
    const FORMATETC& formatEtc,  
    LPTSTR lpszFormat,  
    LPTSTR lpszResult,  
    DWORD flags);

 
void AddFormat(
    UINT cf,  
    DWORD tymed,  
    UINT nFormatID,  
    BOOL bEnableIcon,  
    BOOL bLink);
```  
  
### <a name="parameters"></a>Parâmetros  
 *FMT*  
 Referência ao tipo de dados para adicionar.  
  
 `lpszFormat`  
 Cadeia de caracteres que descreve o formato para o usuário.  
  
 *lpszResult*  
 Cadeia de caracteres que descreve o resultado se esse formato for escolhido na caixa de diálogo.  
  
 `flags`  
 Os diferentes vinculando e inserindo opções disponíveis para esse formato. Esse sinalizador é uma combinação bit a bit de um ou mais dos valores diferentes de **OLEUIPASTEFLAG** tipo enumerado.  
  
 `cf`  
 O formato de área de transferência para adicionar.  
  
 *TYMED*  
 Os tipos de mídia disponíveis neste formato. Esta é uma combinação bit a bit de um ou mais dos valores a **TYMED** tipo enumerado.  
  
 `nFormatID`  
 A ID da cadeia de caracteres que identifica esse formato. O formato dessa cadeia de caracteres é duas cadeias de caracteres separadas separadas por um caractere '\n'. A primeira cadeia de caracteres é o mesmo que seria passado a *lpstrFormat* parâmetro e o segundo é o mesmo que o *lpstrResult* parâmetro.  
  
 *bEnableIcon*  
 Sinalizador que determina se a caixa de seleção Exibir como ícone está habilitada quando esse formato for escolhido na caixa de listagem.  
  
 *Intermitência*  
 Sinalizador que determina se o botão de opção de colar Link está habilitado quando esse formato for escolhido na caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
 Essa função pode ser chamada para adicionar qualquer um dos formatos padrão como **CF_TEXT** ou **CF_TIFF** ou formatos personalizados que seu aplicativo registrado com o sistema. Para obter mais informações sobre a colagem de objetos de dados em seu aplicativo, consulte o artigo [objetos de dados e fontes de dados: manipulação](../../mfc/data-objects-and-data-sources-manipulation.md).  
  
 Para obter mais informações, consulte o [TYMED](http://msdn.microsoft.com/library/windows/desktop/ms691227) tipo de enumeração e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura no SDK do Windows.  
  
 Para obter mais informações, consulte o [OLEUIPASTEFLAG](http://msdn.microsoft.com/library/windows/desktop/ms682172) enumerados tipo no SDK do Windows.  
  
##  <a name="addlinkentry"></a>COlePasteSpecialDialog::AddLinkEntry  
 Adiciona uma nova entrada à lista de formatos com suporte de área de transferência.  
  
```  
OLEUIPASTEFLAG AddLinkEntry(UINT cf);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cf`  
 O formato de área de transferência para adicionar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [OLEUIPASTEFLAG](http://msdn.microsoft.com/library/windows/desktop/ms682172) estrutura que contém as informações para a nova entrada de link.  
  
##  <a name="addstandardformats"></a>COlePasteSpecialDialog::AddStandardFormats  
 Chame essa função para adicionar os seguintes formatos de área de transferência para a lista de formatos de que seu aplicativo pode dar suporte em uma operação de colar especial:  
  
```  
void AddStandardFormats(BOOL bEnableLink = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bEnableLink*  
 Sinalizador que determina se é necessário adicionar `CF_LINKSOURCE` à lista de formatos de seu aplicativo pode colar.  
  
### <a name="remarks"></a>Comentários  
  
- **CF_BITMAP**  
  
- **CF_DIB**  
  
- `CF_METAFILEPICT`  
  
- **"Objeto incorporado"**  
  
-   (opcionalmente) **"Vincular origem"**  
  
 Esses formatos são usados para oferecer suporte a incorporação e a vinculação.  
  
##  <a name="colepastespecialdialog"></a>COlePasteSpecialDialog::COlePasteSpecialDialog  
 Constrói um objeto `COlePasteSpecialDialog`.  
  
```  
COlePasteSpecialDialog(
    DWORD dwFlags = PSF_SELECTPASTE,  
    COleDataObject* pDataObject = NULL,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Sinalizador de criação, contém qualquer número de sinalizadores a seguir combinadas que usam o operador OR bit a bit:  
  
- `PSF_SELECTPASTE`Especifica que o botão de opção de colar será verificado inicialmente quando a caixa de diálogo é chamada. Não pode ser usado em combinação com `PSF_SELECTPASTELINK`. Esse é o padrão.  
  
- `PSF_SELECTPASTELINK`Especifica que o Link de colar botão de opção será marcada inicialmente quando a caixa de diálogo é chamada. Não pode ser usado em combinação com `PSF_SELECTPASTE`.  
  
- `PSF_CHECKDISPLAYASICON`Especifica que a caixa de seleção Exibir como ícone será marcada inicialmente quando a caixa de diálogo é chamada.  
  
- `PSF_SHOWHELP`Especifica que o botão de Ajuda será exibido quando a caixa de diálogo é chamada.  
  
 `pDataObject`  
 Aponta para o [COleDataObject](../../mfc/reference/coledataobject-class.md) para colá-lo. Se esse valor for **nulo**, ele obtém o `COleDataObject` da área de transferência.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou o proprietário (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, a janela pai da caixa de diálogo é definida como a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Essa função só constrói um `COlePasteSpecialDialog` objeto. Para exibir a caixa de diálogo, chame o [DoModal](#domodal) função.  
  
 Para obter mais informações, consulte o [OLEUIPASTEFLAG](http://msdn.microsoft.com/library/windows/desktop/ms682172) enumerados tipo no SDK do Windows.  
  
##  <a name="createitem"></a>COlePasteSpecialDialog::CreateItem  
 Cria o novo item que foi escolhido na caixa de diálogo Colar especial.  
  
```  
BOOL CreateItem(COleClientItem* pNewItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pNewItem*  
 Aponta para um `COleClientItem` instância. Não pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item foi criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função só deve ser chamada após [DoModal](#domodal) retorna **IDOK**.  
  
##  <a name="domodal"></a>COlePasteSpecialDialog::DoModal  
 Exibe a caixa de diálogo OLE Colar especial.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
- **IDOK** se a caixa de diálogo foi exibida com êxito.  
  
- **IDCANCEL** se o usuário cancelou a caixa de diálogo.  
  
- **IDABORT** se ocorreu um erro. Se **IDABORT** é retornado, chame o `COleDialog::GetLastError` a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIPasteSpecial](http://msdn.microsoft.com/library/windows/desktop/ms694512) função no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar os vários controles de caixa de diálogo definindo membros do [m_ps](#m_ps) estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Se `DoModal` retorna **IDOK**, você pode chamar outro membro funções para recuperar as configurações ou a entrada de informações pelo usuário na caixa de diálogo.  
  
##  <a name="getdrawaspect"></a>COlePasteSpecialDialog::GetDrawAspect  
 Determina se o usuário optou por exibir o item selecionado como um ícone.  
  
```  
DVASPECT GetDrawAspect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O método necessário para processar o objeto.  
  
- `DVASPECT_CONTENT`Retornado se a caixa de seleção Exibir como ícone não foi verificada quando a caixa de diálogo foi ignorada.  
  
- `DVASPECT_ICON`Retornado se a caixa de seleção Exibir como ícone foi verificada quando a caixa de diálogo foi ignorada.  
  
### <a name="remarks"></a>Comentários  
 Somente chamar esta função após [DoModal](#domodal) retorna **IDOK**.  
  
 Para obter mais informações sobre o aspecto de desenho, consulte o [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura no SDK do Windows.  
  
##  <a name="geticonicmetafile"></a>COlePasteSpecialDialog::GetIconicMetafile  
 Obtém o metarquivo associado ao item selecionado pelo usuário.  
  
```  
HGLOBAL GetIconicMetafile() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para o meta-arquivo que contém o aspecto de ícone do item selecionado, se a caixa de seleção Exibir como ícone foi selecionada quando a caixa de diálogo foi ignorada, escolhendo **Okey**; caso contrário, **nulo**.  
  
##  <a name="getpasteindex"></a>COlePasteSpecialDialog::GetPasteIndex  
 Obtém o valor de índice associado à entrada do usuário selecionado.  
  
```  
int GetPasteIndex() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice na matriz de **OLEUIPASTEENTRY** estruturas que foi selecionado pelo usuário. O formato que corresponde ao índice selecionado deve ser usado ao executar a operação de colagem.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o [OLEUIPASTEENTRY](http://msdn.microsoft.com/library/windows/desktop/ms690165) estrutura no SDK do Windows.  
  
##  <a name="getselectiontype"></a>COlePasteSpecialDialog::GetSelectionType  
 Determina o tipo de seleção feito ao usuário.  
  
```  
UINT GetSelectionType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o tipo de seleção feita.  
  
### <a name="remarks"></a>Comentários  
 Os valores de tipo de retorno são especificados pelo **seleção** tipo de enumeração declarado no `COlePasteSpecialDialog` classe.  
  
```  
enum Selection {
    pasteLink,
    pasteNormal,
    pasteOther,
    pasteStatic
    };  
```  
  
 Execute desccriptions breves desses valores:  
  
- **COlePasteSpecialDialog::pasteLink** botão o Link de colar foi verificada e o formato escolhido era um formato padrão de OLE.  
  
- **COlePasteSpecialDialog::pasteNormal** botão de opção de colar o foi verificada e o formato escolhido era um formato padrão de OLE.  
  
- **COlePasteSpecialDialog::pasteOther** o formato selecionado não é um formato padrão de OLE.  
  
- **COlePasteSpecialDialog::pasteStatic** o formato selecionado foi metarquivo.  
  
##  <a name="m_ps"></a>COlePasteSpecialDialog::m_ps  
 Estrutura do tipo **OLEUIPASTESPECIAL** usado para controlar o comportamento da caixa de diálogo Colar especial.  
  
```  
OLEUIPASTESPECIAL m_ps;  
```  
  
### <a name="remarks"></a>Comentários  
 Membros dessa estrutura podem ser modificados diretamente ou por meio de funções de membro.  
  
 Para obter mais informações, consulte o [OLEUIPASTESPECIAL](http://msdn.microsoft.com/library/windows/desktop/ms692434) estrutura no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)
