---
title: Classe CRecordView
ms.date: 11/04/2016
f1_keywords:
- CRecordView
- AFXDB/CRecordView
- AFXDB/CRecordView::CRecordView
- AFXDB/CRecordView::IsOnFirstRecord
- AFXDB/CRecordView::IsOnLastRecord
- AFXDB/CRecordView::OnGetRecordset
- AFXDB/CRecordView::OnMove
helpviewer_keywords:
- CRecordView [MFC], CRecordView
- CRecordView [MFC], IsOnFirstRecord
- CRecordView [MFC], IsOnLastRecord
- CRecordView [MFC], OnGetRecordset
- CRecordView [MFC], OnMove
- CRecordView [MFC], OnMove
ms.assetid: 9b4b0897-bd50-4d48-a0b4-f3323f5ccc55
ms.openlocfilehash: c7013fb53562fd76744bff19d1d37ce972a52d52
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643853"
---
# <a name="crecordview-class"></a>Classe CRecordView

Uma exibição que exibe registros de banco de dados em controles.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CRecordView : public CFormView
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CRecordView::CRecordView](#crecordview)|Constrói um objeto `CRecordView`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRecordView::IsOnFirstRecord](#isonfirstrecord)|Retorna diferente de zero se o registro atual é o primeiro registro no conjunto de registros associado.|
|[CRecordView::IsOnLastRecord](#isonlastrecord)|Retorna diferente de zero se o registro atual é o último registro no conjunto de registros associado.|
|[CRecordView::OnGetRecordset](#ongetrecordset)|Retorna um ponteiro para um objeto de uma classe derivada de `CRecordset`. ClassWizard substitui essa função para você e cria o conjunto de registros, se necessário.|
|[CRecordView::OnMove](#onmove)||

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CRecordView::OnMove](#onmove)|Se o registro atual foi alterado, atualiza-la na fonte de dados e, em seguida, move para o registro especificado (próximo, anterior, primeiro ou último).|

## <a name="remarks"></a>Comentários

A exibição é um modo de exibição de formulário conectado diretamente a um `CRecordset` objeto. O modo de exibição é criado a partir de um recurso de modelo de caixa de diálogo e exibe os campos do `CRecordset` objeto nos controles do modelo de caixa de diálogo. O `CRecordView` objeto usa a troca de dados de caixa de diálogo (DDX) e registrar troca de campos (RFX) para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de registros. `CRecordView` também fornece uma implementação padrão para a movimentação para o primeiro, próximo, anterior ou o último registro e uma interface para atualizar o registro no momento no modo de exibição.

> [!NOTE]
>  Se você estiver trabalhando com as classes de objetos de acesso a dados (DAO) em vez das classes de conectividade de banco de dados aberto (ODBC), use a classe [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) em vez disso. Para obter mais informações, consulte o artigo [visão geral: banco de dados de programação](../../data/data-access-programming-mfc-atl.md).

É a maneira mais comum para criar a exibição de registro com o Assistente de aplicativo. Assistente de aplicativo Tge cria a classe de exibição de registro e sua classe de conjunto de registros associado como parte do seu aplicativo de esqueleto starter. Se você não criar a classe de exibição de registro com o Assistente de aplicativo, você pode criá-lo mais tarde com ClassWizard. Se você simplesmente precisa de um único formulário, a abordagem do Assistente de aplicativo é mais fácil. ClassWizard permite que você decida usar uma exibição de registro mais tarde no processo de desenvolvimento. Usar ClassWizard para criar uma exibição de registro e um conjunto de registros separadamente e, em seguida, conectá-los é a abordagem mais flexível porque isso lhe dará mais controle para nomear a classe de conjunto de registros e seu. H /. Arquivos CPP. Essa abordagem também permite que você tenha vários modos de exibição de registro da mesma classe de conjunto de registros.

Para tornar mais fácil para os usuários finais mover de registro para registro na exibição do registro, o Assistente de aplicativo cria menus (e, opcionalmente, barra de ferramentas) recursos para mover para o primeiro, próximo, anterior ou o último registro. Se você criar uma classe de exibição de registro com ClassWizard, você precisa criar esses recursos por conta própria com o menu e bitmap editores.

Para obter informações sobre a implementação padrão para a movimentação de registro em registro, consulte `IsOnFirstRecord` e `IsOnLastRecord` e o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).

`CRecordView` mantém controle da posição do usuário no conjunto de registros, para que o modo de exibição de registro possa atualizar a interface do usuário. Quando o usuário move para ambas as extremidades do conjunto de registros, o modo de exibição do registro desabilita os objetos de interface do usuário — como itens de menu ou botões da barra de ferramentas — para a movimentação adicional na mesma direção.

Para obter mais informações sobre como declarar e usar suas classes de conjunto de registros e a exibição de registro, consulte "Projetando e criando uma exibição do Registro" no artigo [exibições de registro](../../data/record-views-mfc-data-access.md). Para obter mais informações sobre como as exibições de registro de trabalho e como usá-los, consulte o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CScrollView](../../mfc/reference/cscrollview-class.md)

[CFormView](../../mfc/reference/cformview-class.md)

`CRecordView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb. h

##  <a name="crecordview"></a>  CRecordView::CRecordView

Quando você cria um objeto de um tipo derivado de `CRecordView`, chame o formulário do construtor para inicializar o objeto de exibição e identificar o recurso de caixa de diálogo na qual o modo de exibição se baseia.

```
explicit CRecordView(LPCTSTR lpszTemplateName);
explicit CRecordView(UINT nIDTemplate);
```

### <a name="parameters"></a>Parâmetros

*lpszTemplateName*<br/>
Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.

*nIDTemplate*<br/>
Contém o número de identificação de um recurso de modelo de caixa de diálogo.

### <a name="remarks"></a>Comentários

Ou você pode identificar o recurso por nome (passar uma cadeia de caracteres como o argumento para o construtor) ou por sua ID (um inteiro sem sinal, como o argumento de passagem). Usando um recurso de ID é recomendada.

> [!NOTE]
>  Sua classe derivada *deve* fornecer seu próprio construtor. No construtor da classe derivada, chame o construtor `CRecordView::CRecordView` com o nome do recurso ou ID como um argumento, conforme mostrado no exemplo a seguir.

`CRecordView::OnInitialUpdate` chamadas `UpdateData`, que chama `DoDataExchange`. Essa chamada inicial para `DoDataExchange` se conecta `CRecordView` controla (indiretamente) para `CRecordset` os membros de dados criados por ClassWizard de campo. Esses membros de dados não podem ser usados até depois de chamar a classe base `CFormView::OnInitialUpdate` função de membro.

> [!NOTE]
>  Se você usar ClassWizard, o assistente define uma **enum** valor `CRecordView::IDD`, especifica-lo na declaração de classe e usa-lo na lista de inicialização de membro para o construtor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#32](../../mfc/codesnippet/cpp/crecordview-class_1.cpp)]

##  <a name="isonfirstrecord"></a>  CRecordView::IsOnFirstRecord

Chame essa função de membro para determinar se o registro atual é o primeiro registro no objeto recordset associado com este modo de exibição do registro.

```
BOOL IsOnFirstRecord();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o registro atual é o primeiro registro no conjunto de registros; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é útil para escrever suas próprias implementações de padrão de manipuladores de atualização de comando, escritos por ClassWizard.

Se o usuário move para o primeiro registro, o framework desativa quaisquer objetos de interface do usuário que tem para mover para o primeiro ou o registro anterior.

##  <a name="isonlastrecord"></a>  CRecordView::IsOnLastRecord

Chame essa função de membro para determinar se o registro atual é o último registro no objeto recordset associado com este modo de exibição do registro.

```
BOOL IsOnLastRecord();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o registro atual é o último registro no conjunto de registros; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é útil para escrever suas próprias implementações do padrão de manipuladores de atualização de comando que grava de ClassWizard para dar suporte a uma interface do usuário para a movimentação de registro para registro.

> [!CAUTION]
>  O resultado dessa função é confiável, exceto que o modo de exibição não é possível detectar o fim do conjunto de registros até que o usuário passou para ele. O usuário deve mover além do último registro antes da exibição de registro pode dizer que ele deve desabilitar quaisquer objetos de interface do usuário para a movimentação para o próximo ou último registro. Se o usuário move após o último registro e, em seguida, move de volta para o último registro (ou antes dele), o modo de exibição do registro pode controlar a posição do usuário no conjunto de registros e desativar objetos de interface de usuário corretamente. `IsOnLastRecord` também é confiável após uma chamada para a função de implementação `OnRecordLast`, que manipula o comando ID_RECORD_LAST, ou `CRecordset::MoveLast`.

##  <a name="ongetrecordset"></a>  CRecordView::OnGetRecordset

Retorna um ponteiro para o `CRecordset`-derivados do objeto associado com o modo de exibição do registro.

```
virtual CRecordset* OnGetRecordset() = 0;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CRecordset`-objeto derivado, se o objeto foi criado com êxito; caso contrário, um ponteiro NULL.

### <a name="remarks"></a>Comentários

Você deve substituir essa função de membro para construir ou obter um objeto de conjunto de registros e retornar um ponteiro para ele. Se você declarar sua classe de exibição de registro com ClassWizard, o assistente grava uma substituição padrão para você. Implementação do padrão do ClassWizard retorna o ponteiro de conjunto de registros armazenado na exibição do registro, se houver. Se não, ele constrói um objeto de conjunto de registros do tipo especificado com ClassWizard e chama seu `Open` membro de função para abrir a tabela ou executar a consulta e, em seguida, retorna um ponteiro para o objeto.

Para obter mais informações e exemplos, consulte o artigo [exibições de registro: usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).

##  <a name="onmove"></a>  CRecordView::OnMove

Chame essa função de membro para mover para um registro diferente no conjunto de registros e exibir os seus campos nos controles de exibição do registro.

```
virtual BOOL OnMove(UINT nIDMoveCommand);
```

### <a name="parameters"></a>Parâmetros

*nIDMoveCommand*<br/>
Um dos valores de ID de comando padrão a seguir:

- ID_RECORD_FIRST mover para o primeiro registro no conjunto de registros.

- ID_RECORD_LAST mover para o último registro no conjunto de registros.

- ID_RECORD_NEXT mover para o próximo registro no conjunto de registros.

- ID_RECORD_PREV mover para o registro anterior no conjunto de registros.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a movimentação foi bem-sucedida; Caso contrário, 0 se a solicitação de movimentação foi negada.

### <a name="remarks"></a>Comentários

A implementação padrão chama apropriado `Move` função de membro a `CRecordset` objeto associado com o modo de exibição do registro.

Por padrão, `OnMove` atualiza o registro atual na fonte de dados se o usuário foi alterado na exibição do registro.

O Assistente de aplicativo cria um recurso de menu com itens de menu do primeiro registro, o último registro, o próximo registro e registro anterior. Se você selecionar a opção ferramentas acoplável, o Assistente de aplicativo também cria uma barra de ferramentas com botões correspondentes a esses comandos.

Se você mover além do último registro no conjunto de registros, o modo de exibição de registro continua a exibir o último registro. Se você mover para trás após o primeiro registro, o modo de exibição de registro continua a exibir o primeiro registro.

> [!CAUTION]
>  Chamar `OnMove` lança uma exceção se o conjunto de registros não tem registros. Chame a função de manipulador de atualização de interface de usuário apropriado — `OnUpdateRecordFirst`, `OnUpdateRecordLast`, `OnUpdateRecordNext`, ou `OnUpdateRecordPrev` — correspondente antes de mover a operação para determinar se o conjunto de registros tem todos os registros.

## <a name="see-also"></a>Consulte também

[Classe CFormView](../../mfc/reference/cformview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CFormView](../../mfc/reference/cformview-class.md)
