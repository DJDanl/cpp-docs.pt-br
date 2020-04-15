---
title: Classe COleDocument
ms.date: 11/04/2016
f1_keywords:
- COleDocument
- AFXOLE/COleDocument
- AFXOLE/COleDocument::COleDocument
- AFXOLE/COleDocument::AddItem
- AFXOLE/COleDocument::ApplyPrintDevice
- AFXOLE/COleDocument::EnableCompoundFile
- AFXOLE/COleDocument::GetInPlaceActiveItem
- AFXOLE/COleDocument::GetNextClientItem
- AFXOLE/COleDocument::GetNextItem
- AFXOLE/COleDocument::GetNextServerItem
- AFXOLE/COleDocument::GetPrimarySelectedItem
- AFXOLE/COleDocument::GetStartPosition
- AFXOLE/COleDocument::HasBlankItems
- AFXOLE/COleDocument::OnShowViews
- AFXOLE/COleDocument::RemoveItem
- AFXOLE/COleDocument::UpdateModifiedFlag
- AFXOLE/COleDocument::OnEditChangeIcon
- AFXOLE/COleDocument::OnEditConvert
- AFXOLE/COleDocument::OnEditLinks
- AFXOLE/COleDocument::OnFileSendMail
- AFXOLE/COleDocument::OnUpdateEditChangeIcon
- AFXOLE/COleDocument::OnUpdateEditLinksMenu
- AFXOLE/COleDocument::OnUpdateObjectVerbMenu
- AFXOLE/COleDocument::OnUpdatePasteLinkMenu
- AFXOLE/COleDocument::OnUpdatePasteMenu
helpviewer_keywords:
- COleDocument [MFC], COleDocument
- COleDocument [MFC], AddItem
- COleDocument [MFC], ApplyPrintDevice
- COleDocument [MFC], EnableCompoundFile
- COleDocument [MFC], GetInPlaceActiveItem
- COleDocument [MFC], GetNextClientItem
- COleDocument [MFC], GetNextItem
- COleDocument [MFC], GetNextServerItem
- COleDocument [MFC], GetPrimarySelectedItem
- COleDocument [MFC], GetStartPosition
- COleDocument [MFC], HasBlankItems
- COleDocument [MFC], OnShowViews
- COleDocument [MFC], RemoveItem
- COleDocument [MFC], UpdateModifiedFlag
- COleDocument [MFC], OnEditChangeIcon
- COleDocument [MFC], OnEditConvert
- COleDocument [MFC], OnEditLinks
- COleDocument [MFC], OnFileSendMail
- COleDocument [MFC], OnUpdateEditChangeIcon
- COleDocument [MFC], OnUpdateEditLinksMenu
- COleDocument [MFC], OnUpdateObjectVerbMenu
- COleDocument [MFC], OnUpdatePasteLinkMenu
- COleDocument [MFC], OnUpdatePasteMenu
ms.assetid: dc2ecb99-03e1-44c7-bb69-48056dd1b672
ms.openlocfilehash: 51169de521997890190aab52e4afd02ed383af3b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375033"
---
# <a name="coledocument-class"></a>Classe COleDocument

A classe base para documentos OLE que suportam edição visual.

## <a name="syntax"></a>Sintaxe

```
class COleDocument : public CDocument
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDocument::COleDocument](#coledocument)|Constrói um objeto `COleDocument`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDocument::AddItem](#additem)|Adiciona um item à lista de itens mantidos pelo documento.|
|[COleDocument::ApplyPrintDevice](#applyprintdevice)|Define o dispositivo de destino de impressão para todos os itens do cliente no documento.|
|[COleDocument::AtivarComplexoArquivo](#enablecompoundfile)|Faz com que os documentos sejam armazenados usando o formato de arquivo de armazenamento estruturado OLE.|
|[COleDocument::GetInPlaceActiveItem](#getinplaceactiveitem)|Retorna o item OLE que está ativo no momento.|
|[COleDocument::GetNextClientItem](#getnextclientitem)|Recebe o próximo item do cliente para iteração.|
|[COleDocument::GetNextItem](#getnextitem)|Obtém o próximo item do documento para iteração.|
|[COleDocument::GetNextServerItem](#getnextserveritem)|Obtém o próximo item do servidor para iteração.|
|[COleDocument::GetPrimarySelectedItem](#getprimaryselecteditem)|Retorna o item OLE principal selecionado no documento.|
|[COleDocument::GetStartPosition](#getstartposition)|Obtém a posição inicial para iniciar a iteração.|
|[COleDocument::HasBlankItems](#hasblankitems)|Verifica se há itens em branco no documento.|
|[COleDocument::OnShowViews](#onshowviews)|Chamado quando o documento se torna visível ou invisível.|
|[COleDocument::RemoveItem](#removeitem)|Remove um item da lista de itens mantidos pelo documento.|
|[COleDocument::AtualizaçãoModifiedFlag](#updatemodifiedflag)|Marca o documento como modificado se algum dos itens OLE contidos tiver sido modificado.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleDocument::OnEditChangeIcon](#oneditchangeicon)|Lida com eventos no menu Alterar ícone.|
|[COleDocument::OnEditConvert](#oneditconvert)|Lida com a conversão de um objeto incorporado ou vinculado de um tipo para outro.|
|[COleDocument::OnEditLinks](#oneditlinks)|Lida com eventos no comando Links no menu Editar.|
|[COleDocument::OnFileSendMail](#onfilesendmail)|Envia uma mensagem de e-mail com o documento anexado.|
|[COleDocument::OnUpdateEditChangeIcon](#onupdateeditchangeicon)|Chamado pelo framework para atualizar a ui de comando para a opção Editar/Alterar ícone menu.|
|[COleDocument::OnUpdateEditLinksMenu](#onupdateeditlinksmenu)|Chamado pela estrutura para atualizar a ui de comando para a opção Editar/Links menu.|
|[COleDocument::OnUpdateObjectVerbMenu](#onupdateobjectverbmenu)|Chamado pela estrutura para atualizar a ui de comando para a opção Editar/ *ObjetoNome* e o submenu Verbo acessado a partir de Edit/ *ObjectName*.|
|[COleDocument::OnUpdatePasteLinkMenu](#onupdatepastelinkmenu)|Chamado pela estrutura para atualizar a ui de comando para a opção de menu Colar especial.|
|[COleDocument::OnUpdatePasteMenu](#onupdatepastemenu)|Chamado pela estrutura para atualizar a ui de comando para a opção De colar menu.|

## <a name="remarks"></a>Comentários

`COleDocument`é derivado, `CDocument`o que permite que seus aplicativos OLE usem a arquitetura de documento/exibição fornecida pela Microsoft Foundation Class Library.

`COleDocument`trata um documento como uma coleção de objetos [CDocItem](../../mfc/reference/cdocitem-class.md) para lidar com itens OLE. Tanto os aplicativos de contêiner quanto de servidor exigem tal arquitetura, pois seus documentos devem ser capazes de conter itens OLE. As classes [COleServerItem](../../mfc/reference/coleserveritem-class.md) e [COleClientItem,](../../mfc/reference/coleclientitem-class.md) ambas derivadas, `CDocItem`gerenciam as interações entre aplicativos e itens OLE.

Se você estiver escrevendo um aplicativo de `COleDocument`contêiner simples, obtenha sua classe de documento de . Se você estiver escrevendo um aplicativo de contêiner que suporte a vinculação aos itens incorporados contidos por seus documentos, obtenha sua classe de documentos do [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md). Se você estiver escrevendo um aplicativo de servidor ou um contêiner/servidor de combinação, obtenha sua classe de documento do [COleServerDoc](../../mfc/reference/coleserverdoc-class.md). `COleLinkingDoc`e `COleServerDoc` são derivados, `COleDocument`então essas classes herdam todos os serviços disponíveis e `COleDocument` `CDocument`.

Para `COleDocument`usar, obtenha uma classe dele e adicione funcionalidade para gerenciar os dados não-OLE do aplicativo, bem como itens incorporados ou vinculados. Se você `CDocItem`definir classes derivadas para armazenar os dados nativos do aplicativo, você poderá usar a implementação padrão definida para `COleDocument` armazenar seus dados OLE e não-OLE. Você também pode projetar suas próprias estruturas de dados para armazenar seus dados não-OLE separadamente dos itens OLE. Para obter mais informações, consulte o artigo [Containers: Compound Files](../../mfc/containers-compound-files.md)..

`CDocument`suporta o envio do seu documento via correio se o suporte de e-mail (MAPI) estiver presente. `COleDocument`atualizou [o OnFileSendMail](#onfilesendmail) para lidar com documentos compostos corretamente. Para obter mais informações, consulte os artigos [MAPI](../../mfc/mapi.md) e [MAPI Support em MFC](../../mfc/mapi-support-in-mfc.md)..

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Cdocument](../../mfc/reference/cdocument-class.md)

`COleDocument`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="coledocumentadditem"></a><a name="additem"></a>COleDocument::AddItem

Chame esta função para adicionar um item ao documento.

```
virtual void AddItem(CDocItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Ponteiro para o item do documento que está sendo adicionado.

### <a name="remarks"></a>Comentários

Você não precisa chamar essa função explicitamente quando `COleClientItem` ela `COleServerItem` é chamada pelo ou construtor que aceita um ponteiro para um documento.

## <a name="coledocumentapplyprintdevice"></a><a name="applyprintdevice"></a>COleDocument::ApplyPrintDevice

Chame esta função para alterar o dispositivo de destino de impressão para todos os itens [COleClientItem](../../mfc/reference/coleclientitem-class.md) incorporados no documento de contêiner do aplicativo.

```
BOOL ApplyPrintDevice(const DVTARGETDEVICE* ptd);
BOOL ApplyPrintDevice(const PRINTDLG* ppd);
```

### <a name="parameters"></a>Parâmetros

*Ptd*<br/>
Ponteiro para `DVTARGETDEVICE` uma estrutura de dados, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser NULL.

*Ppd*<br/>
Ponteiro para `PRINTDLG` uma estrutura de dados, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser NULL.

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função atualiza o dispositivo de destino de impressão para todos os itens, mas não atualiza o cache de apresentação desses itens. Para atualizar o cache de apresentação de um item, ligue para [COleClientItem::UpdateLink](../../mfc/reference/coleclientitem-class.md#updatelink).

Os argumentos para esta função contêm informações que o OLE usa para identificar o dispositivo de destino. A estrutura [PRINTDLG](/windows/win32/api/commdlg/ns-commdlg-printdlga) contém informações que o Windows usa para inicializar a caixa de diálogo Imprimir comum. Depois que o usuário fecha a caixa de diálogo, o Windows retorna informações sobre as seleções do usuário nesta estrutura. O `m_pd` membro de um objeto `PRINTDLG` [CPrintDialog](../../mfc/reference/cprintdialog-class.md) é uma estrutura.

Para obter mais informações, consulte a estrutura [PRINTDLG](/windows/win32/api/commdlg/ns-commdlg-printdlga) no Windows SDK.

Para obter mais informações, consulte a estrutura [DVTARGETDEVICE](/windows/win32/api/objidl/ns-objidl-dvtargetdevice) no SDK do Windows.

## <a name="coledocumentcoledocument"></a><a name="coledocument"></a>COleDocument::COleDocument

Constrói um objeto `COleDocument`.

```
COleDocument();
```

## <a name="coledocumentenablecompoundfile"></a><a name="enablecompoundfile"></a>COleDocument::AtivarComplexoArquivo

Ligue para esta função se quiser armazenar o documento usando o formato de arquivo composto.

```
void EnableCompoundFile(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
Especifica se o suporte a arquivos compostos está ativado ou desativado.

### <a name="remarks"></a>Comentários

Isso também é chamado de armazenamento estruturado. Você normalmente chama essa função do `COleDocument`construtor de sua classe derivada. Para obter mais informações sobre documentos compostos, consulte o artigo [Containers: Compound Files](../../mfc/containers-compound-files.md)..

Se você não chamar essa função de membro, os documentos serão armazenados em um formato de arquivo não estruturado ("plano").

Depois que o suporte a arquivos compostos for ativado ou desativado para um documento, a configuração não deve ser alterada durante a vida útil do documento.

## <a name="coledocumentgetinplaceactiveitem"></a><a name="getinplaceactiveitem"></a>COleDocument::GetInPlaceActiveItem

Chame esta função para obter o item OLE que está atualmente ativado no lugar na janela do quadro contendo a visualização identificada por *pWnd*.

```
virtual COleClientItem* GetInPlaceActiveItem(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Ponteiro para a janela que exibe o documento do contêiner.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o único item ativo oLE no lugar; NULO se não houver nenhum item OLE atualmente no estado "ativo em vigor".

## <a name="coledocumentgetnextclientitem"></a><a name="getnextclientitem"></a>COleDocument::GetNextClientItem

Ligue para esta função repetidamente para acessar cada um dos itens do cliente em seu documento.

```
COleClientItem* GetNextClientItem(POSITION& pos) const;
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
Uma referência a um valor DE `GetNextClientItem`POSIÇÃO definido por uma chamada anterior para ; o valor inicial é `GetStartPosition` devolvido pela função membro.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o próximo item do cliente no documento, ou NULL se não houver mais itens do cliente.

### <a name="remarks"></a>Comentários

Após cada chamada, o valor do *pos* é definido para o próximo item no documento, que pode ou não ser um item do cliente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#1](../../mfc/codesnippet/cpp/coledocument-class_1.cpp)]

## <a name="coledocumentgetnextitem"></a><a name="getnextitem"></a>COleDocument::GetNextItem

Chame esta função repetidamente para acessar cada um dos itens em seu documento.

```
virtual CDocItem* GetNextItem(POSITION& pos) const;
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
Uma referência a um valor DE `GetNextItem`POSIÇÃO definido por uma chamada anterior para ; o valor inicial é `GetStartPosition` devolvido pela função membro.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o item do documento na posição especificada.

### <a name="remarks"></a>Comentários

Após cada chamada, o valor do *pos* é definido para o valor DE POSIÇÃO do próximo item no documento. Se o elemento recuperado for o último elemento no documento, o novo valor do *pos* será NULO.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#2](../../mfc/codesnippet/cpp/coledocument-class_2.cpp)]

## <a name="coledocumentgetnextserveritem"></a><a name="getnextserveritem"></a>COleDocument::GetNextServerItem

Chame essa função repetidamente para acessar cada um dos itens do servidor em seu documento.

```
COleServerItem* GetNextServerItem(POSITION& pos) const;
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
Uma referência a um valor DE `GetNextServerItem`POSIÇÃO definido por uma chamada anterior para ; o valor inicial é `GetStartPosition` devolvido pela função membro.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o próximo item do servidor no documento, ou NULL se não houver mais itens do servidor.

### <a name="remarks"></a>Comentários

Após cada chamada, o valor do *pos* é definido para o próximo item no documento, que pode ou não ser um item do servidor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleServer#2](../../mfc/codesnippet/cpp/coledocument-class_3.cpp)]

## <a name="coledocumentgetprimaryselecteditem"></a><a name="getprimaryselecteditem"></a>COleDocument::GetPrimarySelectedItem

Chamado pela estrutura para recuperar o item OLE atualmente selecionado na exibição especificada.

```
virtual COleClientItem* GetPrimarySelectedItem(CView* pView);
```

### <a name="parameters"></a>Parâmetros

*pVer*<br/>
Ponteiro para o objeto de exibição ativa exibindo o documento.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o único item OLE selecionado; NULO se nenhum item OLE for selecionado ou se mais de um for selecionado.

### <a name="remarks"></a>Comentários

A implementação padrão pesquisa a lista de itens OLE contidos para um único item selecionado e retorna um ponteiro para ele. Se não houver nenhum item selecionado, ou se houver mais de um item selecionado, a função retorna NULL. Você deve substituir `CView::IsSelected` a função de membro em sua classe de exibição para que essa função funcione. Anular esta função se você tiver seu próprio método de armazenar itens OLE contidos.

## <a name="coledocumentgetstartposition"></a><a name="getstartposition"></a>COleDocument::GetStartPosition

Chame esta função para obter a posição do primeiro item no documento.

```
virtual POSITION GetStartPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de POSIÇÃO que pode ser usado para começar a iterar através dos itens do documento; NULO se o documento não tiver itens.

### <a name="remarks"></a>Comentários

Passe o valor `GetNextItem`devolvido `GetNextClientItem`para, ou `GetNextServerItem`.

## <a name="coledocumenthasblankitems"></a><a name="hasblankitems"></a>COleDocument::HasBlankItems

Ligue para esta função para determinar se o documento contém algum item em branco.

```
BOOL HasBlankItems() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o documento contiver quaisquer itens em branco; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um item em branco é aquele cujo retângulo está vazio.

## <a name="coledocumentoneditchangeicon"></a><a name="oneditchangeicon"></a>COleDocument::OnEditChangeIcon

Exibe a caixa de diálogo Ícone de alteração do OLE e altera o ícone representando o item OLE atualmente selecionado para o ícone que o usuário seleciona na caixa de diálogo.

```
afx_msg void OnEditChangeIcon();
```

### <a name="remarks"></a>Comentários

`OnEditChangeIcon`cria e lança `COleChangeIconDialog` uma caixa de diálogo Alterar ícone.

## <a name="coledocumentoneditconvert"></a><a name="oneditconvert"></a>COleDocument::OnEditConvert

Exibe a caixa de diálogo OLE Converter e converte ou ativa o item OLE atualmente selecionado de acordo com as seleções do usuário na caixa de diálogo.

```
afx_msg void OnEditConvert();
```

### <a name="remarks"></a>Comentários

`OnEditConvert`cria e lança `COleConvertDialog` uma caixa de diálogo Converter.

Um exemplo de conversão é a conversão de um documento do Microsoft Word em um documento do WordPad.

## <a name="coledocumentoneditlinks"></a><a name="oneditlinks"></a>COleDocument::OnEditLinks

Exibe a caixa de diálogo Edição/Links do OLE.

```
afx_msg void OnEditLinks();
```

### <a name="remarks"></a>Comentários

`OnEditLinks`cria e lança `COleLinksDialog` uma caixa de diálogo Links que permite ao usuário alterar os objetos vinculados.

## <a name="coledocumentonfilesendmail"></a><a name="onfilesendmail"></a>COleDocument::OnFileSendMail

Envia uma mensagem através do host de correio residente (se houver) com o documento como anexo.

```
afx_msg void OnFileSendMail();
```

### <a name="remarks"></a>Comentários

`OnFileSendMail`chamadas `OnSaveDocument` para serializar (salvar) documentos sem título e modificados para um arquivo temporário, que é então enviado via correio eletrônico. Se o documento não tiver sido modificado, um arquivo temporário não será necessário; o original é enviado. `OnFileSendMail`cargas MAPI32. DLL se ainda não tiver sido carregado.

Ao contrário `OnFileSendMail` da `CDocument`implementação de for , esta função lida com arquivos compostos corretamente.

Para obter mais informações, consulte os [Tópicos MAPI](../../mfc/mapi.md) e o Suporte MAPI em artigos [de MFC..](../../mfc/mapi-support-in-mfc.md)

## <a name="coledocumentonshowviews"></a><a name="onshowviews"></a>COleDocument::OnShowViews

O framework chama essa função após as alterações do estado de visibilidade do documento.

```
virtual void OnShowViews(BOOL bVisible);
```

### <a name="parameters"></a>Parâmetros

*bVisible*<br/>
Indica se o documento se tornou visível ou invisível.

### <a name="remarks"></a>Comentários

A versão padrão desta função não faz nada. Anular se o aplicativo tiver que realizar qualquer processamento especial quando a visibilidade do documento mudar.

## <a name="coledocumentonupdateeditchangeicon"></a><a name="onupdateeditchangeicon"></a>COleDocument::OnUpdateEditChangeIcon

Chamado pelo framework para atualizar o comando Alterar ícone no menu Editar.

```
afx_msg void OnUpdateEditChangeIcon(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro `CCmdUI` para uma estrutura que representa o menu que gerou o comando de atualização. O manipulador de `Enable` atualização chama `CCmdUI` a função membro da estrutura através *de pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

`OnUpdateEditChangeIcon`atualiza a interface de usuário do comando, dependendo se existe ou não um ícone válido no documento. Anular essa função para mudar o comportamento.

## <a name="coledocumentonupdateeditlinksmenu"></a><a name="onupdateeditlinksmenu"></a>COleDocument::OnUpdateEditLinksMenu

Chamado pela estrutura para atualizar o comando Links no menu Editar.

```
afx_msg void OnUpdateEditLinksMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro `CCmdUI` para uma estrutura que representa o menu que gerou o comando de atualização. O manipulador de `Enable` atualização chama `CCmdUI` a função membro da estrutura através *de pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

Começando com o primeiro item OLE no documento, `OnUpdateEditLinksMenu` acessa cada item, testa se o item é um link e, se é um link, habilita o comando Links. Anular essa função para mudar o comportamento.

## <a name="coledocumentonupdateobjectverbmenu"></a><a name="onupdateobjectverbmenu"></a>COleDocument::OnUpdateObjectVerbMenu

Chamado pela estrutura para atualizar o comando *ObjectName* no menu Editar e o submenu Verbo acessado a partir do comando *ObjectName,* onde *ObjectName* é o nome do objeto OLE incorporado no documento.

```
afx_msg void OnUpdateObjectVerbMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro `CCmdUI` para uma estrutura que representa o menu que gerou o comando de atualização. O manipulador de `Enable` atualização chama `CCmdUI` a função membro da estrutura através *de pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

`OnUpdateObjectVerbMenu`atualiza a interface de usuário do comando *ObjectName,* dependendo se existe ou não um objeto válido no documento. Se existir um objeto, o *comando ObjectName* no menu Editar está ativado. Quando este comando de menu é selecionado, o submenu Verbo é exibido. O submenu Verbo contém todos os comandos verbos disponíveis para o objeto, como Editar, Propriedades e assim por diante. Anular essa função para mudar o comportamento.

## <a name="coledocumentonupdatepastelinkmenu"></a><a name="onupdatepastelinkmenu"></a>COleDocument::OnUpdatePasteLinkMenu

Chamado pela estrutura para determinar se um item OLE vinculado pode ser colado na Área de Transferência.

```
afx_msg void OnUpdatePasteLinkMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro `CCmdUI` para uma estrutura que representa o menu que gerou o comando de atualização. O manipulador de `Enable` atualização chama `CCmdUI` a função membro da estrutura através *de pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

O comando 'Colar's Special menu' está ativado ou desativado, dependendo se o item pode ser colado no documento ou não.

## <a name="coledocumentonupdatepastemenu"></a><a name="onupdatepastemenu"></a>COleDocument::OnUpdatePasteMenu

Chamado pela estrutura para determinar se um item OLE incorporado pode ser colado na Área de Transferência.

```
afx_msg void OnUpdatePasteMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro `CCmdUI` para uma estrutura que representa o menu que gerou o comando de atualização. O manipulador de `Enable` atualização chama `CCmdUI` a função membro da estrutura através *de pCmdUI* para atualizar a interface do usuário.

### <a name="remarks"></a>Comentários

O comando e o botão do menu Colar estão ativados ou desativados, dependendo se o item pode ser colado no documento ou não.

## <a name="coledocumentremoveitem"></a><a name="removeitem"></a>COleDocument::RemoveItem

Chame esta função para remover um item do documento.

```
virtual void RemoveItem(CDocItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Ponteiro para o item do documento a ser removido.

### <a name="remarks"></a>Comentários

Você normalmente não precisa chamar essa função explicitamente; é chamado pelos destruidores para `COleClientItem` e `COleServerItem`.

## <a name="coledocumentupdatemodifiedflag"></a><a name="updatemodifiedflag"></a>COleDocument::AtualizaçãoModifiedFlag

Chame esta função para marcar o documento como modificado se algum dos itens OLE contidos tiver sido modificado.

```
virtual void UpdateModifiedFlag();
```

### <a name="remarks"></a>Comentários

Isso permite que o framework inste o usuário para salvar o documento antes de fechar, mesmo que os dados nativos do documento não tenha sido modificados.

## <a name="see-also"></a>Confira também

[RECIPIENTE de amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[MFC Amostra MFCBIND](../../overview/visual-cpp-samples.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
