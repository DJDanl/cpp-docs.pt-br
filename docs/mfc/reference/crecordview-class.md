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
ms.openlocfilehash: 409739d97c9f7ae9a730ac8f05bd86e647da2c71
ms.sourcegitcommit: ab8d7b47b63b62892a1256a09b1324a9a136eccf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/02/2020
ms.locfileid: "78215541"
---
# <a name="crecordview-class"></a>Classe CRecordView

Uma exibição que exibe registros de banco de dados em controles.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CRecordView : public CFormView
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CRecordView::CRecordView](#crecordview)|Constrói um objeto `CRecordView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CRecordView::IsOnFirstRecord](#isonfirstrecord)|Retornará zero se o registro atual for o primeiro registro no conjunto de registros associado.|
|[CRecordView::IsOnLastRecord](#isonlastrecord)|Retornará zero se o registro atual for o último registro no conjunto de registros associado.|
|[CRecordView::OnGetRecordset](#ongetrecordset)|Retorna um ponteiro para um objeto de uma classe derivada de `CRecordset`. ClassWizard substitui essa função para você e cria o conjunto de registros, se necessário.|
|[CRecordView:: OnMove](#onmove)||

### <a name="protected-methods"></a>Métodos protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CRecordView:: OnMove](#onmove)|Se o registro atual tiver sido alterado, o o atualizará na fonte de dados e moverá para o registro especificado (próximo, anterior, primeiro ou último).|

## <a name="remarks"></a>Comentários

A exibição é uma exibição de formulário diretamente conectada a um objeto `CRecordset`. A exibição é criada a partir de um recurso de modelo de caixa de diálogo e exibe os campos do objeto `CRecordset` nos controles do modelo de caixa de diálogo. O objeto `CRecordView` usa a troca de dados de caixa de diálogo (campo DDX) e a troca de campo de registro (suporte RFX) para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de registros. o `CRecordView` também fornece uma implementação padrão para mover para o primeiro registro, próximo, anterior ou último e uma interface para atualizar o registro atualmente na exibição.

> [!NOTE]
>  Se você estiver trabalhando com as classes DAO (objetos de acesso a dados) em vez das classes ODBC (Open Database Connectivity), use a classe [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) em vez disso. Para obter mais informações, consulte o artigo [visão geral: programação de banco de dados](../../data/data-access-programming-mfc-atl.md).

A maneira mais comum de criar seu modo de exibição de registro é com o assistente de aplicativo. O assistente de aplicativo cria a classe de exibição de registro e sua classe recordset associada como parte de seu aplicativo inicial de esqueleto. Se você não criar a classe de exibição de registro com o assistente de aplicativo, poderá criá-la mais tarde com ClassWizard. Se você simplesmente precisar de um único Formulário, a abordagem do assistente de aplicativo será mais fácil. O ClassWizard permite que você decida usar uma exibição de registro posteriormente no processo de desenvolvimento. O uso de ClassWizard para criar uma exibição de registro e um conjunto de registros separadamente e, em seguida, conectá-los é a abordagem mais flexível, pois fornece mais controle sobre como nomear a classe do conjunto de registros e seu. H/. Arquivos CPP. Essa abordagem também permite que você tenha várias exibições de registro na mesma classe do conjunto de registros.

Para facilitar para os usuários finais a movimentação de registro para registro na exibição de registro, o assistente de aplicativo cria recursos de menu (e, opcionalmente, barra de ferramentas) para mover para o primeiro registro, próximo, anterior ou último. Se você criar uma classe de exibição de registro com ClassWizard, precisará criar esses recursos por conta própria com os editores de menu e bitmap.

Para obter informações sobre a implementação padrão para mover de registro para registro, consulte `IsOnFirstRecord` e `IsOnLastRecord` e o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).

`CRecordView` controla a posição do usuário no conjunto de registros para que a exibição de registro possa atualizar a interface do usuário. Quando o usuário se move para qualquer fim do conjunto de registros, a exibição de registro desabilita os objetos da interface do usuário, como itens de menu ou botões da barra de ferramentas, para avançar na mesma direção.

Para obter mais informações sobre como declarar e usar a exibição de registro e as classes do conjunto de registros, consulte "Projetando e criando uma exibição de registro" nas [exibições de registro](../../data/record-views-mfc-data-access.md)do artigo. Para obter mais informações sobre como as exibições de registro funcionam e como usá-las, consulte o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cvisualização](../../mfc/reference/cview-class.md)

[CScrollView](../../mfc/reference/cscrollview-class.md)

[CFormView](../../mfc/reference/cformview-class.md)

`CRecordView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

##  <a name="crecordview"></a>CRecordView::CRecordView

Quando você cria um objeto de um tipo derivado de `CRecordView`, chame qualquer formulário do construtor para inicializar o objeto View e identifique o recurso de caixa de diálogo no qual a exibição se baseia.

```
explicit CRecordView(LPCTSTR lpszTemplateName);
explicit CRecordView(UINT nIDTemplate);
```

### <a name="parameters"></a>parâmetros

*lpszTemplateName*<br/>
Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.

*nIDTemplate*<br/>
Contém o número de ID de um recurso de modelo de caixa de diálogo.

### <a name="remarks"></a>Comentários

Você pode identificar o recurso por nome (passar uma cadeia de caracteres como o argumento para o Construtor) ou por sua ID (passar um inteiro sem sinal como o argumento). O uso de uma ID de recurso é recomendado.

> [!NOTE]
>  Sua classe derivada *deve* fornecer seu próprio construtor. No construtor de sua classe derivada, chame o Construtor `CRecordView::CRecordView` com o nome do recurso ou ID como um argumento, conforme mostrado no exemplo a seguir.

`CRecordView::OnInitialUpdate` chama `UpdateData`, que chama `DoDataExchange`. Essa chamada inicial para `DoDataExchange` conecta `CRecordView` controles (indiretamente) para `CRecordset` membros de dados de campo criados por ClassWizard. Esses membros de dados não podem ser usados até que você chame a classe base `CFormView::OnInitialUpdate` função membro.

> [!NOTE]
>  Se você usar ClassWizard, o assistente definirá um valor de **enumeração** `CRecordView::IDD`, especificará na declaração de classe e o usará na lista de inicialização de membro para o construtor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#32](../../mfc/codesnippet/cpp/crecordview-class_1.cpp)]

##  <a name="isonfirstrecord"></a>CRecordView::IsOnFirstRecord

Chame essa função de membro para determinar se o registro atual é o primeiro registro no objeto Recordset associado a essa exibição de registro.

```
BOOL IsOnFirstRecord();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o registro atual for o primeiro registro no conjunto de registros; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é útil para escrever suas próprias implementações de manipuladores de atualização de comando padrão escritos por ClassWizard.

Se o usuário mudar para o primeiro registro, a estrutura desabilitará qualquer objeto de interface do usuário que você tenha para mover para o primeiro registro ou para o anterior.

##  <a name="isonlastrecord"></a>CRecordView::IsOnLastRecord

Chame essa função de membro para determinar se o registro atual é o último registro no objeto Recordset associado a essa exibição de registro.

```
BOOL IsOnLastRecord();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o registro atual for o último registro no conjunto de registros; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é útil para escrever suas próprias implementações dos manipuladores de atualização de comando padrão que o ClassWizard grava para dar suporte a uma interface do usuário para mover de registro para registro.

> [!CAUTION]
>  O resultado dessa função é confiável, exceto pelo fato de que a exibição não pode detectar o final do conjunto de registros até que o usuário tenha sido movido para o passado. O usuário deve mover para além do último registro antes que a exibição de registro possa dizer que ele deve desabilitar qualquer objeto de interface do usuário para mover para o próximo registro ou para o último. Se o usuário passar do último registro e voltar para o último registro (ou antes dele), a exibição de registro poderá controlar a posição do usuário no conjunto de registros e desabilitar os objetos da interface do usuário corretamente. `IsOnLastRecord` também não é confiável após uma chamada para a função de implementação `OnRecordLast`, que manipula o comando ID_RECORD_LAST ou `CRecordset::MoveLast`.

##  <a name="ongetrecordset"></a>CRecordView::OnGetRecordset

Retorna um ponteiro para o objeto derivado de `CRecordset`associado à exibição de registro.

```
virtual CRecordset* OnGetRecordset() = 0;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto derivado de `CRecordset`se o objeto foi criado com êxito; caso contrário, um ponteiro nulo.

### <a name="remarks"></a>Comentários

Você deve substituir essa função de membro para construir ou obter um objeto Recordset e retornar um ponteiro para ele. Se você declarar a classe de exibição de registro com ClassWizard, o assistente gravará uma substituição padrão para você. A implementação padrão do ClassWizard retorna o ponteiro do conjunto de registros armazenado na exibição de registro, se houver. Caso contrário, ele constrói um objeto Recordset do tipo que você especificou com ClassWizard e chama sua função de membro `Open` para abrir a tabela ou executar a consulta e, em seguida, retorna um ponteiro para o objeto.

Para obter mais informações e exemplos, consulte o artigo [exibições de registro: usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).

##  <a name="onmove"></a>CRecordView:: OnMove

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

A implementação padrão chama a função membro `Move` apropriada do objeto `CRecordset` associado à exibição de registro.

Por padrão, `OnMove` atualiza o registro atual na fonte de dados se o usuário o alterou na exibição de registro.

O assistente de aplicativo cria um recurso de menu com os itens de menu primeiro registro, último registro, próximo registro e registro anterior. Se você selecionar a opção de barra de ferramentas encaixáveis, o assistente de aplicativo também criará uma barra de ferramentas com botões correspondentes a esses comandos.

Se você mover o último registro no conjunto de registros, a exibição de registro continuará a exibir o último registro. Se você retroceder além do primeiro registro, a exibição de registro continuará a exibir o primeiro registro.

> [!CAUTION]
>  Chamar `OnMove` gera uma exceção se o conjunto de registros não tem registros. Chame a função apropriada do manipulador de atualização da interface do usuário — `OnUpdateRecordFirst`, `OnUpdateRecordLast`, `OnUpdateRecordNext`ou `OnUpdateRecordPrev` — antes da operação de movimentação correspondente para determinar se o conjunto de registros tem algum registro.

## <a name="see-also"></a>Confira também

[Classe CFormView](../../mfc/reference/cformview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CFormView](../../mfc/reference/cformview-class.md)
