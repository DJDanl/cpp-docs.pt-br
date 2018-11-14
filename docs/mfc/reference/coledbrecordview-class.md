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
ms.openlocfilehash: fbbaaae72c7b58f898735d768c019a02cdb7d7e5
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51518574"
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

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDBRecordView::OnGetRowset](#ongetrowset)|Retorna um valor padrão de HRESULT.|
|[COleDBRecordView::OnMove](#onmove)|Atualiza o registro atual (se estiver sujo) na fonte de dados e, em seguida, move para o registro especificado (próximo, anterior, primeiro ou último).|

## <a name="remarks"></a>Comentários

A exibição é um modo de exibição de formulário conectado diretamente a um `CRowset` objeto. O modo de exibição é criado a partir de um recurso de modelo de caixa de diálogo e exibe os campos do `CRowset` objeto nos controles do modelo de caixa de diálogo. O `COleDBRecordView` usa o objeto de troca de dados de caixa de diálogo (DDX) e a funcionalidade de navegação inserida no `CRowset`, para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de linhas. `COleDBRecordView` também fornece uma implementação padrão para a movimentação para o primeiro, próximo, anterior ou o último registro e uma interface para atualizar o registro no momento no modo de exibição.

Você pode usar funções DDX com `COleDbRecordView` obter dados diretamente do conjunto de registros de banco de dados e exibi-lo em um controle de caixa de diálogo. Você deve usar o `DDX_*` métodos (como `DDX_Text`), e não a `DDX_Field*` funções (como `DDX_FieldText`) com `COleDbRecordView`. `DDX_FieldText` não funcionará com `COleDbRecordView` porque `DDX_FieldText` usa um argumento adicional do tipo `CRecordset*` (para `CRecordView`) ou `CDaoRecordset*` (para `CDaoRecordView`).

> [!NOTE]
>  Se você estiver trabalhando com as classes de objetos de acesso a dados (DAO) em vez de OLE DB consumidor classes de modelo, use a classe [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) em vez disso. Para obter mais informações, consulte o artigo [visão geral: banco de dados de programação](../../data/data-access-programming-mfc-atl.md).

`COleDBRecordView` Controla de posição do usuário no conjunto de linhas para que o modo de exibição de registro possa atualizar a interface do usuário. Quando o usuário move para ambas as extremidades do conjunto de linhas, o modo de exibição do registro desabilita os objetos de interface do usuário — como itens de menu ou botões da barra de ferramentas — para a movimentação adicional na mesma direção.

Para obter mais informações sobre classes de conjunto de linhas, consulte o [usando OLE DB modelos de consumidor](../../data/oledb/ole-db-consumer-templates-cpp.md) artigo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CScrollView](../../mfc/reference/cscrollview-class.md)

[CFormView](../../mfc/reference/cformview-class.md)

`COleDBRecordView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxoledb.h

##  <a name="coledbrecordview"></a>  COleDBRecordView::COleDBRecordView

Constrói um objeto `COleDBRecordView`.

```
COleDBRecordView(LPCTSTR lpszTemplateName);
COleDBRecordView(UINT nIDTemplate);
```

### <a name="parameters"></a>Parâmetros

*lpszTemplateName*<br/>
Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.

*nIDTemplate*<br/>
Contém o número de identificação de um recurso de modelo de caixa de diálogo.

### <a name="remarks"></a>Comentários

Quando você cria um objeto de um tipo derivado de `COleDBRecordView`, chamar um dos construtores para criar o objeto de exibição e identificar o recurso de caixa de diálogo na qual o modo de exibição se baseia. Você pode identificar o recurso por nome (passar uma cadeia de caracteres como o argumento para o construtor) ou pela sua ID (um inteiro sem sinal, como o argumento de passagem).

> [!NOTE]
>  Sua classe derivada *deve* fornecer seu próprio construtor. No construtor, invocar o construtor, `COleDBRecordView::COleDBRecordView`, com o nome do recurso ou ID como um argumento.

##  <a name="ongetrowset"></a>  COleDBRecordView::OnGetRowset

Retorna um identificador para o **CRowset <>** objeto associado com o modo de exibição do registro.

```
virtual CRowset<>* OnGetRowset() = 0;
```

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Você deve substituir essa função de membro para construir ou obter um objeto de conjunto de linhas e retornar um identificador a ele. Se você declarar sua classe de exibição de registro com ClassWizard, o assistente grava uma substituição padrão para você. Implementação do padrão do ClassWizard retorna o identificador de conjunto de linhas armazenado na exibição do registro, se houver. Se não, ele constrói um objeto de conjunto de linhas do tipo especificado com ClassWizard e chama seu `Open` membro de função para abrir a tabela ou executar a consulta e, em seguida, retorna um identificador para o objeto.

> [!NOTE]
>  Anteriores ao MFC 7.0 `OnGetRowset` retornou um ponteiro para `CRowset`. Se você tiver um código que chama `OnGetRowset`, você precisará alterar o tipo de retorno para a classe de modelo **CRowset <>**.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#38](../../mfc/codesnippet/cpp/coledbrecordview-class_1.cpp)]

Para obter mais informações e exemplos, consulte o artigo [exibições de registro: usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).

##  <a name="onmove"></a>  COleDBRecordView::OnMove

Move para um registro diferente no conjunto de linhas e exibir seus campos nos controles do registro exibir.

```
virtual BOOL OnMove(UINT nIDMoveCommand);
```

### <a name="parameters"></a>Parâmetros

*nIDMoveCommand*<br/>
Um dos valores de ID de comando padrão a seguir:

- ID_RECORD_FIRST — Mover para o primeiro registro no conjunto de registros.

- ID_RECORD_LAST — Mover para o último registro no conjunto de registros.

- ID_RECORD_NEXT — Mover para o próximo registro no conjunto de registros.

- ID_RECORD_PREV — Mover para o registro anterior no conjunto de registros.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a movimentação foi bem-sucedida; Caso contrário, 0 se a solicitação de movimentação foi negada.

### <a name="remarks"></a>Comentários

A implementação padrão chama apropriado `Move` função de membro a `CRowset` objeto associado com o modo de exibição do registro.

Por padrão, `OnMove` atualiza o registro atual na fonte de dados se o usuário foi alterado na exibição do registro.

O Assistente de aplicativo cria um recurso de menu com itens de menu do primeiro registro, o último registro, o próximo registro e registro anterior. Se você selecionar a opção ferramentas acoplável, o Assistente de aplicativo também cria uma barra de ferramentas com botões correspondentes a esses comandos.

Se você mover além do último registro no conjunto de registros, o modo de exibição de registro continua a exibir o último registro. Se você mover para trás após o primeiro registro, o modo de exibição de registro continua a exibir o primeiro registro.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

