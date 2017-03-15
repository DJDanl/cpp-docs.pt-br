---
title: Classe COleDocument | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleDocument
dev_langs:
- C++
helpviewer_keywords:
- COleDocument class
- OLE documents, base class
- OLE containers, client items
- visual editing, OLE document base class
- OLE documents
- documents, OLE
ms.assetid: dc2ecb99-03e1-44c7-bb69-48056dd1b672
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 73bd1bc5c2c93e180b42a79cf23ab98360887c31
ms.lasthandoff: 02/25/2017

---
# <a name="coledocument-class"></a>Classe COleDocument
A classe base para documentos OLE que dão suporte à edição visual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleDocument : public CDocument  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDocument::COleDocument](#coledocument)|Constrói um objeto `COleDocument`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDocument::AddItem](#additem)|Adiciona um item à lista de itens mantidos pelo documento.|  
|[COleDocument::ApplyPrintDevice](#applyprintdevice)|Define o dispositivo de destino de impressão para todos os itens de cliente no documento.|  
|[COleDocument::EnableCompoundFile](#enablecompoundfile)|Faz com que os documentos sejam armazenados usando o formato de arquivo de armazenamento estruturado OLE.|  
|[COleDocument::GetInPlaceActiveItem](#getinplaceactiveitem)|Retorna o item OLE que está ativo no momento no local.|  
|[COleDocument::GetNextClientItem](#getnextclientitem)|Obtém o próximo item do cliente para fazer a iteração.|  
|[COleDocument::GetNextItem](#getnextitem)|Obtém o próximo item de documento para iteração.|  
|[COleDocument::GetNextServerItem](#getnextserveritem)|Obtém o próximo item de servidor para fazer a iteração.|  
|[COleDocument::GetPrimarySelectedItem](#getprimaryselecteditem)|Retorna o item OLE selecionado primário no documento.|  
|[COleDocument::GetStartPosition](#getstartposition)|Obtém a posição inicial para começar a iteração.|  
|[COleDocument::HasBlankItems](#hasblankitems)|Verifica se há itens em branco no documento.|  
|[COleDocument::OnShowViews](#onshowviews)|Chamado quando o documento se torna visível ou invisível.|  
|[COleDocument::RemoveItem](#removeitem)|Remove um item da lista de itens mantidos pelo documento.|  
|[COleDocument::UpdateModifiedFlag](#updatemodifiedflag)|Marca o documento como modificado se qualquer um dos itens contidos OLE foram modificadas.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDocument::OnEditChangeIcon](#oneditchangeicon)|Manipula eventos no comando de menu Alterar ícone.|  
|[COleDocument::OnEditConvert](#oneditconvert)|Manipula a conversão de um objeto vinculado ou incorporado de um tipo para outro.|  
|[COleDocument::OnEditLinks](#oneditlinks)|Manipula eventos no comando Links no menu Editar.|  
|[COleDocument::OnFileSendMail](#onfilesendmail)|Envia uma mensagem de email com o documento anexado.|  
|[COleDocument::OnUpdateEditChangeIcon](#onupdateeditchangeicon)|Chamado pela estrutura para atualizar a interface de comando para a opção do menu Editar/Alterar ícone.|  
|[COleDocument::OnUpdateEditLinksMenu](#onupdateeditlinksmenu)|Chamado pela estrutura para atualizar a interface de comando para a opção do menu Editar/Links.|  
|[COleDocument::OnUpdateObjectVerbMenu](#onupdateobjectverbmenu)|Chamado pela estrutura para atualizar a interface de comando para editar / *ObjectName* opção de menu e o submenu de verbo acessados de edição / *ObjectName*.|  
|[COleDocument::OnUpdatePasteLinkMenu](#onupdatepastelinkmenu)|Chamado pela estrutura para atualizar a interface de comando para a opção de menu Colar especial.|  
|[COleDocument::OnUpdatePasteMenu](#onupdatepastemenu)|Chamado pela estrutura para atualizar a interface de comando para a opção de menu colar.|  
  
## <a name="remarks"></a>Comentários  
 `COleDocument`é derivado de **CDocument**, que permite que seus aplicativos OLE usam a arquitetura de exibição de documentos fornecida pelo Microsoft Foundation Class Library.  
  
 `COleDocument`trata de um documento como uma coleção de [CDocItem](../../mfc/reference/cdocitem-class.md) objetos para processar itens de OLE. Aplicativos de contêiner e o servidor exigirem tal arquitetura porque seus documentos devem ser capazes de conter itens OLE. O [classe derivada COleServerItem](../../mfc/reference/coleserveritem-class.md) e [COleClientItem](../../mfc/reference/coleclientitem-class.md) classes derivadas de `CDocItem`, gerenciar as interações entre os aplicativos e itens OLE.  
  
 Se você estiver escrevendo um aplicativo de contêiner simples, derive sua classe de documento da `COleDocument`. Se você estiver escrevendo um aplicativo de contêiner que dá suporte à vinculação para os itens inseridos contidos em seus documentos, derive sua classe de documento da [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md). Se você estiver escrevendo um servidor de aplicativo ou uma combinação de contêiner/servidor, derive sua classe de documento da [COleServerDoc](../../mfc/reference/coleserverdoc-class.md). `COleLinkingDoc`e `COleServerDoc` são derivados de `COleDocument`, portanto, essas classes herdam todos os serviços disponíveis no `COleDocument` e **CDocument**.  
  
 Para usar `COleDocument`, derivar uma classe dela e adicionar funcionalidade para gerenciar o aplicativo OLE não dados, bem como os itens inseridos ou vinculados. Se você definir `CDocItem`-derivadas de classes para armazenar os dados do aplicativo nativo, você pode usar a implementação do padrão definida pela `COleDocument` para armazenar dados não são OLE e o OLE. Você também pode criar suas próprias estruturas de dados para armazenar seus dados não são OLE separadamente dos itens de OLE. Para obter mais informações, consulte o artigo [contêineres: arquivos compostos](../../mfc/containers-compound-files.md)...  
  
 **CDocument** oferece suporte ao envio de seu documento por email se houver suporte mail (MAPI). `COleDocument`atualizou [OnFileSendMail](#onfilesendmail) para manipular documentos compostos corretamente. Para obter mais informações, consulte os artigos [MAPI](../../mfc/mapi.md) e [suporte a MAPI no MFC](../../mfc/mapi-support-in-mfc.md)...  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocument](../../mfc/reference/cdocument-class.md)  
  
 `COleDocument`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="a-nameadditema--coledocumentadditem"></a><a name="additem"></a>COleDocument::AddItem  
 Chame essa função para adicionar um item ao documento.  
  
```  
virtual void AddItem(CDocItem* pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Ponteiro para o item de documento que está sendo adicionado.  
  
### <a name="remarks"></a>Comentários  
 Você não precisa chamar essa função explicitamente quando ele é chamado pelo `COleClientItem` ou `COleServerItem` construtor que aceita um ponteiro para um documento.  
  
##  <a name="a-nameapplyprintdevicea--coledocumentapplyprintdevice"></a><a name="applyprintdevice"></a>COleDocument::ApplyPrintDevice  
 Chame essa função para alterar o dispositivo de destino de impressão para todos inseridos [COleClientItem](../../mfc/reference/coleclientitem-class.md) itens no documento do contêiner do aplicativo.  
  
```  
BOOL ApplyPrintDevice(const DVTARGETDEVICE* ptd);  
BOOL ApplyPrintDevice(const PRINTDLG* ppd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptd`  
 Ponteiro para uma **DVTARGETDEVICE** estrutura de dados, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser **nulo**.  
  
 `ppd`  
 Ponteiro para uma **PRINTDLG** estrutura de dados, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função atualiza o dispositivo de destino de impressão para todos os itens, mas não atualiza o cache de apresentação para esses itens. Para atualizar o cache de apresentação para um item, chame [COleClientItem::UpdateLink](../../mfc/reference/coleclientitem-class.md#updatelink).  
  
 Os argumentos para essa função contêm informações que OLE usa para identificar o dispositivo de destino. O [PRINTDLG](http://msdn.microsoft.com/library/windows/desktop/ms646843) estrutura contém informações que o Windows usa para inicializar a caixa de diálogo de impressão comuns. Depois que o usuário fecha a caixa de diálogo, o Windows retorna informações sobre as seleções do usuário nessa estrutura. O `m_pd` membro de um [CPrintDialog](../../mfc/reference/cprintdialog-class.md) objeto é um **PRINTDLG** estrutura.  
  
 Para obter mais informações, consulte o [PRINTDLG](http://msdn.microsoft.com/library/windows/desktop/ms646843) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações, consulte o [DVTARGETDEVICE](http://msdn.microsoft.com/library/windows/desktop/ms686613) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namecoledocumenta--coledocumentcoledocument"></a><a name="coledocument"></a>COleDocument::COleDocument  
 Constrói um objeto `COleDocument`.  
  
```  
COleDocument();
```  
  
##  <a name="a-nameenablecompoundfilea--coledocumentenablecompoundfile"></a><a name="enablecompoundfile"></a>COleDocument::EnableCompoundFile  
 Chame essa função se você deseja armazenar o documento usando o formato de arquivo composto.  
  
```  
void EnableCompoundFile(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnable`  
 Especifica se o suporte de arquivo composto está habilitado ou desabilitado.  
  
### <a name="remarks"></a>Comentários  
 Isso também é chamado de armazenamento estruturado. Normalmente você chama essa função do construtor de seu `COleDocument`-classe derivada. Para obter mais informações sobre documentos compostos, consulte o artigo [contêineres: arquivos compostos](../../mfc/containers-compound-files.md)...  
  
 Se você não chamar essa função de membro, os documentos serão armazenados em um formato nonstructured ("simples").  
  
 Depois de suporte de arquivo composto está habilitada ou desabilitada para um documento, a configuração não deve ser alterada durante o tempo de vida do documento.  
  
##  <a name="a-namegetinplaceactiveitema--coledocumentgetinplaceactiveitem"></a><a name="getinplaceactiveitem"></a>COleDocument::GetInPlaceActiveItem  
 Chamada para essa função para obter a OLE item que estiver ativada no local na janela do quadro que contém a exibição identificada por `pWnd`.  
  
```  
virtual COleClientItem* GetInPlaceActiveItem(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Ponteiro para a janela que exibe o documento contêiner.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o único, no local OLE item ativo; **Nulo** se há nenhum item OLE atualmente no estado "ativo no local".  
  
##  <a name="a-namegetnextclientitema--coledocumentgetnextclientitem"></a><a name="getnextclientitem"></a>COleDocument::GetNextClientItem  
 Chame essa função repetidamente para acessar cada um dos itens de cliente no documento.  
  
```  
COleClientItem* GetNextClientItem(POSITION& pos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 Uma referência a um **posição** valor conjunto por uma chamada anterior a `GetNextClientItem`; o valor inicial é retornado pelo `GetStartPosition` função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o próximo item do cliente no documento, ou **nulo** se não houver nenhum outro item do cliente.  
  
### <a name="remarks"></a>Comentários  
 Após cada chamada, o valor de `pos` é definida para o próximo item no documento, que pode ou não ser um item do cliente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer n º&1;](../../mfc/codesnippet/cpp/coledocument-class_1.cpp)]  
  
##  <a name="a-namegetnextitema--coledocumentgetnextitem"></a><a name="getnextitem"></a>COleDocument::GetNextItem  
 Chame essa função repetidamente para acessar cada um dos itens no seu documento.  
  
```  
virtual CDocItem* GetNextItem(POSITION& pos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 Uma referência a um **posição** valor conjunto por uma chamada anterior a `GetNextItem`; o valor inicial é retornado pelo `GetStartPosition` função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o item de documento na posição especificada.  
  
### <a name="remarks"></a>Comentários  
 Após cada chamada, o valor de `pos` é definido como o **posição** valor do próximo item no documento. Se o elemento recuperado é o último elemento no documento, o novo valor de `pos` é **nulo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer n º&2;](../../mfc/codesnippet/cpp/coledocument-class_2.cpp)]  
  
##  <a name="a-namegetnextserveritema--coledocumentgetnextserveritem"></a><a name="getnextserveritem"></a>COleDocument::GetNextServerItem  
 Chame essa função repetidamente para acessar cada um dos itens de servidor em seu documento.  
  
```  
COleServerItem* GetNextServerItem(POSITION& pos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 Uma referência a um **posição** valor conjunto por uma chamada anterior a `GetNextServerItem`; o valor inicial é retornado pelo `GetStartPosition` função de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o próximo item de servidor no documento, ou **nulo** se não houver nenhum outro item de servidor.  
  
### <a name="remarks"></a>Comentários  
 Após cada chamada, o valor de `pos` é definida para o próximo item no documento, que pode ou não ser um item de servidor.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleServer n º&2;](../../mfc/codesnippet/cpp/coledocument-class_3.cpp)]  
  
##  <a name="a-namegetprimaryselecteditema--coledocumentgetprimaryselecteditem"></a><a name="getprimaryselecteditem"></a>COleDocument::GetPrimarySelectedItem  
 Chamado pela estrutura para recuperar o item OLE selecionado no modo de exibição especificado.  
  
```  
virtual COleClientItem* GetPrimarySelectedItem(CView* pView);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pView`  
 Ponteiro para o objeto de exibição ativa exibindo o documento.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o item OLE selecionado, único; **Nulo** se nenhum item OLE selecionado ou se mais de um for selecionado.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão de pesquisa a lista de independente OLE itens para um único item selecionado e retorna um ponteiro para ele. Se não há nenhum item selecionado ou, se houver mais de um item selecionado, a função retorna **nulo**. Você deve substituir o `CView::IsSelected` a função de membro em sua classe de exibição para essa função de trabalho. Substitua essa função se você tiver seu próprio método para armazenar os itens contidos OLE.  
  
##  <a name="a-namegetstartpositiona--coledocumentgetstartposition"></a><a name="getstartposition"></a>COleDocument::GetStartPosition  
 Chame essa função para obter a posição do primeiro item no documento.  
  
```  
virtual POSITION GetStartPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **posição** valor que pode ser usado para iniciar a iteração por meio dos itens do documento; **Nulo** se o documento não tem nenhum item.  
  
### <a name="remarks"></a>Comentários  
 Passar o valor retornado para `GetNextItem`, `GetNextClientItem`, ou `GetNextServerItem`.  
  
##  <a name="a-namehasblankitemsa--coledocumenthasblankitems"></a><a name="hasblankitems"></a>COleDocument::HasBlankItems  
 Chame essa função para determinar se o documento contém todos os itens em branco.  
  
```  
BOOL HasBlankItems() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o documento contém todos os itens em branco; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um item em branco é aquele cujo retângulo está vazio.  
  
##  <a name="a-nameoneditchangeicona--coledocumentoneditchangeicon"></a><a name="oneditchangeicon"></a>COleDocument::OnEditChangeIcon  
 Exibe a caixa de diálogo OLE alterar ícone e altera o ícone que representa o item OLE selecionado para o ícone que o usuário seleciona na caixa de diálogo.  
  
```  
afx_msg void OnEditChangeIcon();
```  
  
### <a name="remarks"></a>Comentários  
 `OnEditChangeIcon`cria e inicia um `COleChangeIconDialog` caixa de diálogo Alterar ícone.  
  
##  <a name="a-nameoneditconverta--coledocumentoneditconvert"></a><a name="oneditconvert"></a>COleDocument::OnEditConvert  
 Exibe a caixa de diálogo converter OLE e converte ou ativa o item OLE selecionado de acordo com as seleções do usuário na caixa de diálogo.  
  
```  
afx_msg void OnEditConvert();
```  
  
### <a name="remarks"></a>Comentários  
 `OnEditConvert`cria e inicia um `COleConvertDialog` caixa de diálogo Converter.  
  
 Um exemplo de conversão é converter um documento do Microsoft Word em um documento do WordPad.  
  
##  <a name="a-nameoneditlinksa--coledocumentoneditlinks"></a><a name="oneditlinks"></a>COleDocument::OnEditLinks  
 Exibe a caixa de diálogo Editar/Links OLE.  
  
```  
afx_msg void OnEditLinks();
```  
  
### <a name="remarks"></a>Comentários  
 `OnEditLinks`cria e inicia um `COleLinksDialog` caixa de diálogo de Links que permite ao usuário alterar os objetos vinculados.  
  
##  <a name="a-nameonfilesendmaila--coledocumentonfilesendmail"></a><a name="onfilesendmail"></a>COleDocument::OnFileSendMail  
 Envia uma mensagem por meio do host de correio residentes (se houver) com o documento como um anexo.  
  
```  
afx_msg void OnFileSendMail();
```  
  
### <a name="remarks"></a>Comentários  
 `OnFileSendMail`chamadas `OnSaveDocument` para serializar (documentos sem título e modificados para um arquivo temporário, que é enviado por email Salvar). Se o documento não tiver sido modificado, um arquivo temporário não é necessário; o original é enviado. `OnFileSendMail`carrega MAPI32. DLL se ele ainda não tenha sido carregado.  
  
 Ao contrário da implementação de `OnFileSendMail` para **CDocument**, essa função manipula arquivos compostos corretamente.  
  
 Para obter mais informações, consulte o [MAPI tópicos](../../mfc/mapi.md) e [suporte a MAPI no MFC](../../mfc/mapi-support-in-mfc.md) artigos...  
  
##  <a name="a-nameonshowviewsa--coledocumentonshowviews"></a><a name="onshowviews"></a>COleDocument::OnShowViews  
 O framework chama essa função após a visibilidade do documento, as alterações de estado.  
  
```  
virtual void OnShowViews(BOOL bVisible);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bVisible`  
 Indica se o documento ficou visível ou invisível.  
  
### <a name="remarks"></a>Comentários  
 A versão padrão dessa função não faz nada. Substituí-lo se seu aplicativo deve executar qualquer processamento especial quando a visibilidade do documento é alterado.  
  
##  <a name="a-nameonupdateeditchangeicona--coledocumentonupdateeditchangeicon"></a><a name="onupdateeditchangeicon"></a>COleDocument::OnUpdateEditChangeIcon  
 Chamado pela estrutura para atualizar o comando Alterar ícone no menu Editar.  
  
```  
afx_msg void OnUpdateEditChangeIcon(CCmdUI* pCmdUI);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Um ponteiro para um `CCmdUI` estrutura que representa o menu que gerou o comando update. As chamadas do manipulador de atualização de **habilitar** função de membro a `CCmdUI` estrutura por meio de `pCmdUI` para atualizar a interface do usuário.  
  
### <a name="remarks"></a>Comentários  
 `OnUpdateEditChangeIcon`Atualiza a interface do usuário do comando dependendo se existe ou não um ícone válido no documento. Substitua essa função para alterar o comportamento.  
  
##  <a name="a-nameonupdateeditlinksmenua--coledocumentonupdateeditlinksmenu"></a><a name="onupdateeditlinksmenu"></a>COleDocument::OnUpdateEditLinksMenu  
 Chamado pela estrutura para atualizar o comando vínculos no menu Editar.  
  
```  
afx_msg void OnUpdateEditLinksMenu(CCmdUI* pCmdUI);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Um ponteiro para um `CCmdUI` estrutura que representa o menu que gerou o comando update. As chamadas do manipulador de atualização de **habilitar** função de membro a `CCmdUI` estrutura por meio de `pCmdUI` para atualizar a interface do usuário.  
  
### <a name="remarks"></a>Comentários  
 Começando com o primeiro item OLE no documento, `OnUpdateEditLinksMenu` acessa cada item, testa se o item é um link e, se ele é um link, permite que o comando de Links. Substitua essa função para alterar o comportamento.  
  
##  <a name="a-nameonupdateobjectverbmenua--coledocumentonupdateobjectverbmenu"></a><a name="onupdateobjectverbmenu"></a>COleDocument::OnUpdateObjectVerbMenu  
 Chamado pela estrutura para atualizar o *ObjectName* comando no menu Editar e no submenu de verbo acessado a partir de *ObjectName* comando, onde *ObjectName* é o nome do objeto OLE incorporado ao documento.  
  
```  
afx_msg void OnUpdateObjectVerbMenu(CCmdUI* pCmdUI);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Um ponteiro para um `CCmdUI` estrutura que representa o menu que gerou o comando update. As chamadas do manipulador de atualização de **habilitar** função de membro a `CCmdUI` estrutura por meio de `pCmdUI` para atualizar a interface do usuário.  
  
### <a name="remarks"></a>Comentários  
 `OnUpdateObjectVerbMenu`atualizações de *ObjectName* interface de usuário do comando dependendo se existe ou não um objeto válido no documento. Se existir um objeto, o *ObjectName* comando no menu Editar está habilitado. Quando esse comando de menu é selecionado, o submenu verbo é exibido. O submenu verbo contém todos os comandos de verbo disponíveis para o objeto, como editar, propriedades e assim por diante. Substitua essa função para alterar o comportamento.  
  
##  <a name="a-nameonupdatepastelinkmenua--coledocumentonupdatepastelinkmenu"></a><a name="onupdatepastelinkmenu"></a>COleDocument::OnUpdatePasteLinkMenu  
 Chamado pela estrutura para determinar se um item OLE vinculado pode ser colado da área de transferência.  
  
```  
afx_msg void OnUpdatePasteLinkMenu(CCmdUI* pCmdUI);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Um ponteiro para um `CCmdUI` estrutura que representa o menu que gerou o comando update. As chamadas do manipulador de atualização de **habilitar** função de membro a `CCmdUI` estrutura por meio de `pCmdUI` para atualizar a interface do usuário.  
  
### <a name="remarks"></a>Comentários  
 O comando de menu Colar especial está habilitado ou desabilitado dependendo se o item pode ser colado no documento ou não.  
  
##  <a name="a-nameonupdatepastemenua--coledocumentonupdatepastemenu"></a><a name="onupdatepastemenu"></a>COleDocument::OnUpdatePasteMenu  
 Chamado pela estrutura para determinar se um item OLE incorporado pode ser colado da área de transferência.  
  
```  
afx_msg void OnUpdatePasteMenu(CCmdUI* pCmdUI);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Um ponteiro para um `CCmdUI` estrutura que representa o menu que gerou o comando update. As chamadas do manipulador de atualização de **habilitar** função de membro a `CCmdUI` estrutura por meio de `pCmdUI` para atualizar a interface do usuário.  
  
### <a name="remarks"></a>Comentários  
 O comando de menu colar e o botão estão habilitados ou desabilitados dependendo se o item pode ser colado no documento ou não.  
  
##  <a name="a-nameremoveitema--coledocumentremoveitem"></a><a name="removeitem"></a>COleDocument::RemoveItem  
 Chame essa função para remover um item do documento.  
  
```  
virtual void RemoveItem(CDocItem* pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Ponteiro para o item de documento a ser removido.  
  
### <a name="remarks"></a>Comentários  
 Você normalmente não precisa chamar essa função explicitamente. ele é chamado pelos destruidores de `COleClientItem` e `COleServerItem`.  
  
##  <a name="a-nameupdatemodifiedflaga--coledocumentupdatemodifiedflag"></a><a name="updatemodifiedflag"></a>COleDocument::UpdateModifiedFlag  
 Chame essa função para marcar o documento como modificado se qualquer um dos itens contidos OLE foram modificadas.  
  
```  
virtual void UpdateModifiedFlag();
```  
  
### <a name="remarks"></a>Comentários  
 Isso permite que o framework avisar o usuário para salvar o documento antes de fechar, mesmo se os dados nativos do documento não foi modificados.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CONTÊINER](../../visual-cpp-samples.md)   
 [Exemplo MFC MFCBIND](../../visual-cpp-samples.md)   
 [Classe CDocument](../../mfc/reference/cdocument-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




