---
title: Classe CDaoRecordView
ms.date: 11/04/2016
f1_keywords:
- CDaoRecordView
- AFXDAO/CDaoRecordView
- AFXDAO/CDaoRecordView::CDaoRecordView
- AFXDAO/CDaoRecordView::IsOnFirstRecord
- AFXDAO/CDaoRecordView::IsOnLastRecord
- AFXDAO/CDaoRecordView::OnGetRecordset
- AFXDAO/CDaoRecordView::OnMove
helpviewer_keywords:
- CDaoRecordView [MFC], CDaoRecordView
- CDaoRecordView [MFC], IsOnFirstRecord
- CDaoRecordView [MFC], IsOnLastRecord
- CDaoRecordView [MFC], OnGetRecordset
- CDaoRecordView [MFC], OnMove
ms.assetid: 5aa7d0e2-bd05-413e-b216-80c404ce18ac
ms.openlocfilehash: 95ed9207d0047287e373401da52f05235a817999
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223129"
---
# <a name="cdaorecordview-class"></a>Classe CDaoRecordView

Uma exibição que exibe registros de banco de dados em controles.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CDaoRecordView : public CFormView
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CDaoRecordView::CDaoRecordView](#cdaorecordview)|Constrói um objeto `CDaoRecordView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoRecordView::IsOnFirstRecord](#isonfirstrecord)|Retornará zero se o registro atual for o primeiro registro no conjunto de registros associado.|
|[CDaoRecordView::IsOnLastRecord](#isonlastrecord)|Retornará zero se o registro atual for o último registro no conjunto de registros associado.|
|[CDaoRecordView::OnGetRecordset](#ongetrecordset)|Retorna um ponteiro para um objeto de uma classe derivada de `CDaoRecordset` . ClassWizard substitui essa função para você e cria o conjunto de registros, se necessário.|
|[CDaoRecordView:: OnMove](#onmove)|Se o registro atual tiver sido alterado, o o atualizará na fonte de dados e moverá para o registro especificado (próximo, anterior, primeiro ou último).|

## <a name="remarks"></a>Comentários

A exibição é uma exibição de formulário diretamente conectada a um `CDaoRecordset` objeto. A exibição é criada a partir de um recurso de modelo de caixa de diálogo e exibe os campos do `CDaoRecordset` objeto nos controles do modelo de caixa de diálogo. O `CDaoRecordView` objeto usa troca de dados de caixa de diálogo (campo DDX) e intercâmbio de campo de registro DAO (DFX) para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de registros. `CDaoRecordView`também fornece uma implementação padrão para mover para o primeiro registro, próximo, anterior ou último e uma interface para atualizar o registro atualmente na exibição.

> [!NOTE]
> As classes de banco de dados DAO são diferentes das classes de banco de dados MFC baseadas em ODBC (Open Database Connectivity). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO; as classes DAO geralmente oferecem recursos superiores porque usam o mecanismo de banco de dados do Microsoft Jet.

A maneira mais comum de criar seu modo de exibição de registro é com o assistente de aplicativo. O assistente de aplicativo cria a classe de exibição de registro e sua classe recordset associada como parte de seu aplicativo inicial de esqueleto.

Se você simplesmente precisar de um único Formulário, a abordagem do assistente de aplicativo será mais fácil. O ClassWizard permite que você decida usar uma exibição de registro posteriormente no processo de desenvolvimento. Se você não criar a classe de exibição de registro com o assistente de aplicativo, poderá criá-la mais tarde com ClassWizard. O uso de ClassWizard para criar uma exibição de registro e um conjunto de registros separadamente e, em seguida, conectá-los é a abordagem mais flexível, pois fornece mais controle sobre como nomear a classe do conjunto de registros e seu. H/. Arquivos CPP. Essa abordagem também permite que você tenha várias exibições de registro na mesma classe do conjunto de registros.

Para facilitar para os usuários finais a movimentação de registro para registro na exibição de registro, o assistente de aplicativo cria recursos de menu (e, opcionalmente, barra de ferramentas) para mover para o primeiro registro, próximo, anterior ou último. Se você criar uma classe de exibição de registro com ClassWizard, precisará criar esses recursos por conta própria com os editores de menu e bitmap.

Para obter informações sobre a implementação padrão para mover de registro para registro, consulte `IsOnFirstRecord` e `IsOnLastRecord` e o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md), que se aplica ao e ao `CRecordView` `CDaoRecordView` .

`CDaoRecordView`controla a posição do usuário no conjunto de registros para que a exibição de registro possa atualizar a interface do usuário. Quando o usuário se move para qualquer fim do conjunto de registros, a exibição de registro desabilita os objetos da interface do usuário, como itens de menu ou botões da barra de ferramentas, para avançar na mesma direção.

Para obter mais informações sobre como declarar e usar a exibição de registro e as classes do conjunto de registros, consulte "Projetando e criando uma exibição de registro" nas [exibições de registro](../../data/record-views-mfc-data-access.md)do artigo. Para obter mais informações sobre como as exibições de registro funcionam e como usá-las, consulte o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md). Todos os artigos mencionados acima se aplicam ao `CRecordView` e ao `CDaoRecordView` .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CScrollView](../../mfc/reference/cscrollview-class.md)

[CFormView](../../mfc/reference/cformview-class.md)

`CDaoRecordView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="cdaorecordviewcdaorecordview"></a><a name="cdaorecordview"></a>CDaoRecordView::CDaoRecordView

Quando você cria um objeto de um tipo derivado de `CDaoRecordView` , chame qualquer forma do construtor para inicializar o objeto View e identificar o recurso de caixa de diálogo no qual a exibição se baseia.

```
explicit CDaoRecordView(LPCTSTR lpszTemplateName);
explicit CDaoRecordView(UINT nIDTemplate);
```

### <a name="parameters"></a>parâmetros

*lpszTemplateName*<br/>
Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.

*nIDTemplate*<br/>
Contém o número de ID de um recurso de modelo de caixa de diálogo.

### <a name="remarks"></a>Comentários

Você pode identificar o recurso por nome (passar uma cadeia de caracteres como o argumento para o Construtor) ou por sua ID (passar um inteiro sem sinal como o argumento). O uso de uma ID de recurso é recomendado.

> [!NOTE]
> Sua classe derivada deve fornecer seu próprio construtor. No construtor de sua classe derivada, chame o construtor `CDaoRecordView::CDaoRecordView` com o nome do recurso ou ID como um argumento.

`CDaoRecordView::OnInitialUpdate`chamadas `CWnd::UpdateData` , que chamam `CWnd::DoDataExchange` . Essa chamada inicial para `DoDataExchange` conectar `CDaoRecordView` controles (indiretamente) a `CDaoRecordset` membros de dados de campo criados por ClassWizard. Esses membros de dados não podem ser usados até que você chame a função de membro da classe base `CFormView::OnInitialUpdate` .

> [!NOTE]
> Se você usar ClassWizard, o assistente definirá um **`enum`** valor `CDaoRecordView::IDD` na declaração de classe e o usará na lista de inicialização do membro para o construtor.

[!code-cpp[NVC_MFCDatabase#35](../../mfc/codesnippet/cpp/cdaorecordview-class_1.cpp)]

## <a name="cdaorecordviewisonfirstrecord"></a><a name="isonfirstrecord"></a>CDaoRecordView::IsOnFirstRecord

Chame essa função de membro para determinar se o registro atual é o primeiro registro no objeto Recordset associado a essa exibição de registro.

```
BOOL IsOnFirstRecord();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o registro atual for o primeiro registro no conjunto de registros; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é útil para escrever suas próprias implementações dos manipuladores de atualização de comando padrão escritos por ClassWizard.

Se o usuário mudar para o primeiro registro, a estrutura desabilitará todos os objetos da interface do usuário (por exemplo, itens de menu ou botões da barra de ferramentas) que você tem para mover para o primeiro registro ou para o anterior.

## <a name="cdaorecordviewisonlastrecord"></a><a name="isonlastrecord"></a>CDaoRecordView::IsOnLastRecord

Chame essa função de membro para determinar se o registro atual é o último registro no objeto Recordset associado a essa exibição de registro.

```
BOOL IsOnLastRecord();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o registro atual for o último registro no conjunto de registros; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é útil para escrever suas próprias implementações dos manipuladores de atualização de comando padrão que o ClassWizard grava para dar suporte a uma interface do usuário para mover de registro para registro.

> [!CAUTION]
> O resultado dessa função é confiável, exceto pelo fato de que a exibição pode não ser capaz de detectar o final do conjunto de registros até que o usuário tenha sido movido para o passado. O usuário pode precisar ir além do último registro antes que a exibição de registro possa dizer que ele deve desabilitar qualquer objeto de interface do usuário para mover para o próximo registro ou para o último. Se o usuário passar do último registro e voltar para o último registro (ou antes dele), a exibição de registro poderá controlar a posição do usuário no conjunto de registros e desabilitar os objetos da interface do usuário corretamente.

## <a name="cdaorecordviewongetrecordset"></a><a name="ongetrecordset"></a>CDaoRecordView::OnGetRecordset

Retorna um ponteiro para o `CDaoRecordset` objeto derivado associado à exibição de registro.

```
virtual CDaoRecordset* OnGetRecordset() = 0;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um `CDaoRecordset` objeto derivado se o objeto foi criado com êxito; caso contrário, um ponteiro nulo.

### <a name="remarks"></a>Comentários

Você deve substituir essa função de membro para construir ou obter um objeto Recordset e retornar um ponteiro para ele. Se você declarar a classe de exibição de registro com ClassWizard, o assistente gravará uma substituição padrão para você. A implementação padrão do ClassWizard retorna o ponteiro do conjunto de registros armazenado na exibição de registro, se houver. Caso contrário, ele construirá um objeto Recordset do tipo especificado com ClassWizard e chamará sua `Open` função de membro para abrir a tabela ou executar a consulta e, em seguida, retornará um ponteiro para o objeto.

Para obter mais informações e exemplos, consulte o artigo [exibições de registro: usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).

## <a name="cdaorecordviewonmove"></a><a name="onmove"></a>CDaoRecordView:: OnMove

Chame essa função de membro para mover para um registro diferente no conjunto de registros e exibir seus campos nos controles da exibição de registro.

```
virtual BOOL OnMove(UINT nIDMoveCommand);
```

### <a name="parameters"></a>parâmetros

*nIDMoveCommand*<br/>
Um dos seguintes valores de ID de comando padrão:

- ID_RECORD_FIRST mover para o primeiro registro no conjunto de registros.

- ID_RECORD_LAST Mover para o último registro no conjunto de registros.

- ID_RECORD_NEXT Mover para o próximo registro no conjunto de registros.

- ID_RECORD_PREV mover para o registro anterior no conjunto de registros.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a movimentação foi bem-sucedida; caso contrário, 0 se a solicitação de movimentação foi negada.

### <a name="remarks"></a>Comentários

A implementação padrão chama a função de membro de movimentação apropriada do `CDaoRecordset` objeto associado à exibição de registro.

Por padrão, `OnMove` o atualiza o registro atual na fonte de dados se o usuário o alterou na exibição de registro.

O assistente de aplicativo cria um recurso de menu com os itens de menu primeiro registro, último registro, próximo registro e registro anterior. Se você selecionar a opção de barra de ferramentas inicial, o assistente de aplicativo também criará uma barra de ferramentas com botões correspondentes a esses comandos.

Se você mover o último registro no conjunto de registros, a exibição de registro continuará a exibir o último registro. Se você retroceder além do primeiro registro, a exibição de registro continuará a exibir o primeiro registro.

> [!CAUTION]
> Chamar `OnMove` gera uma exceção se o conjunto de registros não tiver registros. Chame a função apropriada do manipulador de atualização da interface do usuário — `OnUpdateRecordFirst` ,, `OnUpdateRecordLast` `OnUpdateRecordNext` ou `OnUpdateRecordPrev` — antes da operação de movimentação correspondente para determinar se o conjunto de registros tem algum registro.

## <a name="see-also"></a>Confira também

[Classe CFormView](../../mfc/reference/cformview-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)<br/>
[Classe CFormView](../../mfc/reference/cformview-class.md)
