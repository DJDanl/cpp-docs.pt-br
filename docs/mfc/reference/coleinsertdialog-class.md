---
title: Classe COleInsertDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleInsertDialog
- AFXODLGS/COleInsertDialog
- AFXODLGS/COleInsertDialog::COleInsertDialog
- AFXODLGS/COleInsertDialog::CreateItem
- AFXODLGS/COleInsertDialog::DoModal
- AFXODLGS/COleInsertDialog::GetClassID
- AFXODLGS/COleInsertDialog::GetDrawAspect
- AFXODLGS/COleInsertDialog::GetIconicMetafile
- AFXODLGS/COleInsertDialog::GetPathName
- AFXODLGS/COleInsertDialog::GetSelectionType
- AFXODLGS/COleInsertDialog::m_io
dev_langs:
- C++
helpviewer_keywords:
- OLE Insert Object dialog box
- dialog boxes, OLE
- COleInsertDialog class
- Insert Object dialog box
ms.assetid: a9ec610b-abde-431e-bd01-c40159a66dbb
caps.latest.revision: 24
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 078f421dacc79ff929249cd35c520b0c4d4a222e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="coleinsertdialog-class"></a>Classe COleInsertDialog
Usado para a caixa de diálogo Inserir objeto OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleInsertDialog : public COleDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleInsertDialog::COleInsertDialog](#coleinsertdialog)|Constrói um objeto `COleInsertDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleInsertDialog::CreateItem](#createitem)|Cria o item selecionado na caixa de diálogo.|  
|[COleInsertDialog::DoModal](#domodal)|Exibe a caixa de diálogo Inserir objeto OLE.|  
|[COleInsertDialog::GetClassID](#getclassid)|Obtém o **CLSID** associado ao item escolhido.|  
|[COleInsertDialog::GetDrawAspect](#getdrawaspect)|Informa se desenhar o item como um ícone.|  
|[COleInsertDialog::GetIconicMetafile](#geticonicmetafile)|Obtém um identificador para o metarquivo associado ao formulário icônico deste item.|  
|[COleInsertDialog::GetPathName](#getpathname)|Obtém o caminho completo para o arquivo selecionado na caixa de diálogo.|  
|[COleInsertDialog::GetSelectionType](#getselectiontype)|Obtém o tipo de objeto selecionado.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleInsertDialog::m_io](#m_io)|Uma estrutura do tipo **OLEUIINSERTOBJECT** que controla o comportamento da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Criar um objeto da classe `COleInsertDialog` quando você deseja chamar essa caixa de diálogo. Após um `COleInsertDialog` objeto foi construído, você pode usar o [m_io](#m_io) estrutura para inicializar os valores ou os estados de controles na caixa de diálogo. O `m_io` estrutura é do tipo **OLEUIINSERTOBJECT**. Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte o [DoModal](#domodal) função de membro.  
  
> [!NOTE]
>  Código do contêiner gerado pelo Assistente de aplicativo usa essa classe.  
  
 Para obter mais informações, consulte o [OLEUIINSERTOBJECT](http://msdn.microsoft.com/library/windows/desktop/ms691316) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleInsertDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
##  <a name="coleinsertdialog"></a>COleInsertDialog::COleInsertDialog  
 Essa função só constrói uma `COleInsertDialog` objeto.  
  
```  
COleInsertDialog (
    DWORD dwFlags = IOF_SELECTCREATENEW,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Sinalizador de criação que contém qualquer número de valores a seguir para ser combinado com o operador OR bit a bit:  
  
- **IOF_SHOWHELP** Especifica que o botão de Ajuda será exibido quando a caixa de diálogo é chamada.  
  
- **IOF_SELECTCREATENEW** Especifica que o botão Criar novo será selecionado inicialmente quando a caixa de diálogo é chamada. Este é o padrão e não pode ser usada com **IOF_SELECTCREATEFROMFILE**.  
  
- **IOF_SELECTCREATEFROMFILE** Especifica que o botão de opção Criar do arquivo será selecionado inicialmente quando a caixa de diálogo é chamada. Não pode ser usada com **IOF_SELECTCREATENEW**.  
  
- **IOF_CHECKLINK** Especifica que a caixa de seleção do Link será marcada inicialmente quando a caixa de diálogo é chamada.  
  
- **IOF_DISABLELINK** Especifica que a caixa de seleção do Link será desabilitada quando a caixa de diálogo é chamada.  
  
- **IOF_CHECKDISPLAYASICON** Especifica que a caixa de seleção Exibir como ícone será verificada inicialmente, o ícone atual será exibido e o botão Alterar ícone será habilitado quando a caixa de diálogo é chamada.  
  
- **IOF_VERIFYSERVERSEXIST** Especifica que a caixa de diálogo deve validar as classes adiciona à caixa de listagem, garantindo que os servidores especificados no banco de dados do Registro existirem antes da caixa de diálogo é exibida. Defina esse sinalizador pode prejudicar o desempenho significativamente.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou proprietário (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, a janela pai do objeto de caixa de diálogo é definida para a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Para exibir a caixa de diálogo, chame o [DoModal](#domodal) função.  
  
##  <a name="createitem"></a>COleInsertDialog::CreateItem  
 Chame essa função para criar um objeto do tipo [COleClientItem](../../mfc/reference/coleclientitem-class.md) somente se [DoModal](#domodal) retorna **IDOK**.  
  
```  
BOOL CreateItem(COleClientItem* pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Aponta para o item a ser criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item foi criado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você deve alocar o `COleClientItem` antes de chamar essa função do objeto.  
  
##  <a name="domodal"></a>COleInsertDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo Inserir objeto OLE.  
  
```  
virtual INT_PTR   
    DoModal();

 
INT_PTR   
    DoModal(DWORD  dwFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Um dos seguintes valores:  
  
 `COleInsertDialog::DocObjectsOnly`Insere somente DocObjects.  
  
 `COleInsertDialog::ControlsOnly`Insere somente os controles ActiveX.  
  
 Zero insere um DocObject nem um controle ActiveX. Esse valor resulta na mesma implementação como protótipo primeiro listados acima.  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
-   IDOK se a caixa de diálogo foi exibida com êxito.  
  
-   IDCANCEL se o usuário cancelou a caixa de diálogo.  
  
-   IDABORT se ocorreu um erro. Se IDABORT for retornado, chame o [COleDialog::GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIInsertObject](http://msdn.microsoft.com/library/windows/desktop/ms694325) funcionar a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar os vários controles de caixa de diálogo definindo membros do [m_io](#m_io) estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Se `DoModal` retorna IDOK, você pode chamar funções para recuperar a entrada de informações na caixa de diálogo pelo usuário ou configurações de outro membro.  
  
##  <a name="getclassid"></a>COleInsertDialog::GetClassID  
 Chame essa função para obter o **CLSID** associados com o item selecionado apenas se [DoModal](#domodal) retorna **IDOK** e é o tipo de seleção **COleInsertDialog::createNewItem**.  
  
```  
REFCLSID GetClassID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o **CLSID** associado ao item selecionado.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [chave CLSID](http://msdn.microsoft.com/library/windows/desktop/ms691424) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getdrawaspect"></a>COleInsertDialog::GetDrawAspect  
 Chame essa função para determinar se o usuário optar por exibir o item selecionado como um ícone.  
  
```  
DVASPECT GetDrawAspect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O método necessário para processar o objeto.  
  
- `DVASPECT_CONTENT`Retornado se a caixa de seleção Exibir como ícone não foi selecionada.  
  
- `DVASPECT_ICON`Retornado se a caixa de seleção Exibir como ícone foi verificada.  
  
### <a name="remarks"></a>Comentários  
 Chamar isso apenas se função [DoModal](#domodal) retorna **IDOK**.  
  
 Para obter mais informações sobre os aspectos de desenho, consulte [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) na estrutura de dados de [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="geticonicmetafile"></a>COleInsertDialog::GetIconicMetafile  
 Chame essa função para obter um identificador para o metarquivo que contém o aspecto icônico do item selecionado.  
  
```  
HGLOBAL GetIconicMetafile() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para o metarquivo contendo o aspecto icônico do item selecionado, se a caixa de seleção Exibir como ícone foi marcada quando a caixa de diálogo foi ignorada, escolhendo **Okey**; caso contrário, **nulo**.  
  
##  <a name="getpathname"></a>COleInsertDialog::GetPathName  
 Chame essa função para obter o caminho completo do apenas se o arquivo selecionado [DoModal](#domodal) retorna **IDOK** e o tipo de seleção não é **COleInsertDialog::createNewItem**.  
  
```  
CString GetPathName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O caminho completo para o arquivo selecionado na caixa de diálogo. Se o tipo de seleção é `createNewItem`, essa função retorna um sentido `CString` no modo de versão ou provoca uma asserção no modo de depuração.  
  
##  <a name="getselectiontype"></a>COleInsertDialog::GetSelectionType  
 Chame essa função para obter o tipo de seleção escolhido quando a caixa de diálogo Inserir objeto foi ignorada, escolhendo **Okey**.  
  
```  
UINT GetSelectionType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Tipo de seleção feita.  
  
### <a name="remarks"></a>Comentários  
 Os valores de tipo de retorno são especificados pelo **seleção** tipo de enumeração declarada no `COleInsertDialog` classe.  
  
```  
enum Selection {
    createNewItem,
    insertFromFile,
    linkToFile
    };  
```  
  
 Execute as breves descrições desses valores:  
  
- **COleInsertDialog::createNewItem** a criar novo botão de opção foi selecionada.  
  
- **COleInsertDialog::insertFromFile** botão de opção de criar o do arquivo foi selecionado e a caixa de seleção do Link não foi verificada.  
  
- **COleInsertDialog::linkToFile** botão de opção de criar o do arquivo foi selecionado e a caixa de seleção do Link foi verificada.  
  
##  <a name="m_io"></a>COleInsertDialog::m_io  
 Estrutura do tipo **OLEUIINSERTOBJECT** usado para controlar o comportamento da caixa de diálogo Inserir objeto.  
  
```  
OLEUIINSERTOBJECT m_io;  
```  
  
### <a name="remarks"></a>Comentários  
 Membros dessa estrutura podem ser modificados diretamente ou através de funções de membro.  
  
 Para obter mais informações, consulte o [OLEUIINSERTOBJECT](http://msdn.microsoft.com/library/windows/desktop/ms691316) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)

