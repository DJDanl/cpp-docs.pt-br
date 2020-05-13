---
title: Classe COleDBRecordView
ms.date: 11/04/2016
f1_keywords:
- COleDBRecordView
- AFXOLEDB/COleDBRecordView
- AFXOLEDB/COleDBRecordView::COleDBRecordView
- AFXOLEDB/COleDBRecordView::OnGetRowset
- AFXOLEDB/COleDBRecordView::OnMove
helpviewer_keywords:
- COleDBRecordView [MFC], COleDBRecordView
- COleDBRecordView [MFC], OnGetRowset
- COleDBRecordView [MFC], OnMove
ms.assetid: 98612427-c4c9-4760-b7e1-85b17448add9
ms.openlocfilehash: de9c602cb747ee3d4449df479530e55ce907cb8a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366099"
---
# <a name="coledbrecordview-class"></a>Classe COleDBRecordView

Uma exibição que exibe registros de banco de dados em controles.

## <a name="syntax"></a>Sintaxe

```
class COleDBRecordView : public CFormView
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleDBRecordView::COleDBRecordView](#coledbrecordview)|Constrói um objeto `COleDBRecordView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDBRecordView::OnGetRowset](#ongetrowset)|Retorna um valor HRESULT padrão.|
|[COleDBRecordView::OnMove](#onmove)|Atualiza o registro atual (se sujo) na fonte de dados e, em seguida, passa para o registro especificado (próximo, anterior, primeiro ou último).|

## <a name="remarks"></a>Comentários

A exibição é uma exibição de formulário diretamente conectada a um `CRowset` objeto. A exibição é criada a partir de um `CRowset` recurso de modelo de diálogo e exibe os campos do objeto nos controles do modelo de diálogo. O `COleDBRecordView` objeto usa o DDX (Exchange de dados `CRowset`de diálogo) e a funcionalidade de navegação incorporada, para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de linhas. `COleDBRecordView`também fornece uma implementação padrão para mover para o primeiro, próximo, anterior ou último registro e uma interface para atualizar o registro atualmente em exibição.

Você pode usar funções `COleDbRecordView` DDX com para obter dados diretamente do conjunto de registros do banco de dados e exibi-los em um controle de diálogo. Você deve `DDX_*` usar os métodos (como), `DDX_Text`não as `DDX_Field*` funções (como `DDX_FieldText`) com `COleDbRecordView`. `DDX_FieldText`não funcionará `COleDbRecordView` `DDX_FieldText` com isso porque `CRecordset*` leva `CRecordView`um `CDaoRecordset*` argumento `CDaoRecordView`adicional de tipo (para ) ou (para ).

> [!NOTE]
> Se você estiver trabalhando com as classes DAO (Data Access Objects, objetos de acesso de dados) em vez das classes OLE DB Consumer Template, use a classe [CDaoRecordView.](../../mfc/reference/cdaorecordview-class.md) Para obter mais informações, consulte a visão geral do [artigo: Programação de banco de dados](../../data/data-access-programming-mfc-atl.md).

`COleDBRecordView`mantém o controle da posição do usuário no conjunto de linhas para que a visualização do registro possa atualizar a interface do usuário. Quando o usuário se move para o final do conjunto de linhas, a visualização de registro desativa objetos de interface do usuário — como itens de menu ou botões de barra de ferramentas — para se mover mais na mesma direção.

Para obter mais informações sobre classes de conjunto de linhas, consulte o artigo [Usando modelos de consumo do OLE DB.](../../data/oledb/ole-db-consumer-templates-cpp.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CScrollView](../../mfc/reference/cscrollview-class.md)

[CFormView](../../mfc/reference/cformview-class.md)

`COleDBRecordView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxoledb.h

## <a name="coledbrecordviewcoledbrecordview"></a><a name="coledbrecordview"></a>COleDBRecordView::COleDBRecordView

Constrói um objeto `COleDBRecordView`.

```
COleDBRecordView(LPCTSTR lpszTemplateName);
COleDBRecordView(UINT nIDTemplate);
```

### <a name="parameters"></a>Parâmetros

*lpszTemplateName*<br/>
Contém uma seqüência de seqüência de terminadas nula que é o nome de um recurso de modelo de diálogo.

*Nidtemplate*<br/>
Contém o número de ID de um recurso de modelo de diálogo.

### <a name="remarks"></a>Comentários

Quando você criar um objeto de `COleDBRecordView`um tipo derivado, invoque um dos construtores para criar o objeto de exibição e identifique o recurso de diálogo no qual a exibição é baseada. Você pode identificar o recurso pelo nome (passar uma string como argumento para o construtor) ou pelo seu ID (passar um inteiro não assinado como argumento).

> [!NOTE]
> Sua classe derivada *deve* fornecer seu próprio construtor. Na construtora, invoque o `COleDBRecordView::COleDBRecordView`construtor, com o nome do recurso ou ID como argumento.

## <a name="coledbrecordviewongetrowset"></a><a name="ongetrowset"></a>COleDBRecordView::OnGetRowset

Retorna uma alça para o **objeto<>CRowset** associado à exibição de registro.

```
virtual CRowset<>* OnGetRowset() = 0;
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Você deve substituir esta função de membro para construir ou obter um objeto de conjunto de linhas e retornar uma alça para ele. Se você declarar sua classe de exibição de gravação com o ClassWizard, o assistente escreverá uma substituição padrão para você. A implementação padrão do ClassWizard retorna a alça de conjunto de linhas armazenada na exibição de registro se existir. Se não, ele constrói um objeto de conjunto de linhas do `Open` tipo especificado com o ClassWizard e chama sua função de membro para abrir a tabela ou executar a consulta e, em seguida, retorna uma alça para o objeto.

> [!NOTE]
> Antes do MFC 7.0, `OnGetRowset` devolveu um ponteiro para `CRowset`. Se você tiver `OnGetRowset`código que chama, você precisa alterar o tipo de retorno para a classe **templatized CRowset<>**.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#38](../../mfc/codesnippet/cpp/coledbrecordview-class_1.cpp)]

Para obter mais informações e exemplos, consulte o artigo [Record Views: Usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).

## <a name="coledbrecordviewonmove"></a><a name="onmove"></a>COleDBRecordView::OnMove

Move-se para um registro diferente no conjunto de linhas e exibe seus campos nos controles da exibição de registro.

```
virtual BOOL OnMove(UINT nIDMoveCommand);
```

### <a name="parameters"></a>Parâmetros

*nIDMoveCommand*<br/>
Um dos seguintes valores de ID de comando padrão:

- ID_RECORD_FIRST — Passar para o primeiro disco no conjunto de discos.

- ID_RECORD_LAST — Passar para o último disco no conjunto de discos.

- ID_RECORD_NEXT — Passar para o próximo disco no conjunto de discos.

- ID_RECORD_PREV — Passar para o recorde anterior no conjunto de discos.

### <a name="return-value"></a>Valor retornado

Não zero se a mudança foi bem sucedida; caso contrário 0 se o pedido de mudança foi negado.

### <a name="remarks"></a>Comentários

A implementação padrão `Move` chama a `CRowset` função de membro apropriado do objeto associado à exibição de registro.

Por padrão, `OnMove` atualiza o registro atual na fonte de dados se o usuário o alterou na exibição de registro.

O Assistente de aplicativo cria um recurso de menu com itens de menu Primeiro Registro, Último Registro, Próximo Registro e Registro Anterior. Se você selecionar a opção Barra de Ferramentas Docas, o Assistente de Aplicativo também criará uma barra de ferramentas com botões correspondentes a esses comandos.

Se você passar do último registro no conjunto de discos, a exibição de discos continuará a exibir o último registro. Se você passar para trás após o primeiro registro, a visualização de registro continua a exibir o primeiro registro.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
