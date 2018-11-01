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
ms.openlocfilehash: db1636bebd0cc29124018b5fad2c0535079706d3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50541200"
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

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoRecordView::IsOnFirstRecord](#isonfirstrecord)|Retorna diferente de zero se o registro atual é o primeiro registro no conjunto de registros associado.|
|[CDaoRecordView::IsOnLastRecord](#isonlastrecord)|Retorna diferente de zero se o registro atual é o último registro no conjunto de registros associado.|
|[CDaoRecordView::OnGetRecordset](#ongetrecordset)|Retorna um ponteiro para um objeto de uma classe derivada de `CDaoRecordset`. ClassWizard substitui essa função para você e cria o conjunto de registros, se necessário.|
|[CDaoRecordView::OnMove](#onmove)|Se o registro atual foi alterado, atualiza-la na fonte de dados e, em seguida, move para o registro especificado (próximo, anterior, primeiro ou último).|

## <a name="remarks"></a>Comentários

A exibição é um modo de exibição de formulário conectado diretamente a um `CDaoRecordset` objeto. O modo de exibição é criado a partir de um recurso de modelo de caixa de diálogo e exibe os campos do `CDaoRecordset` objeto nos controles do modelo de caixa de diálogo. O `CDaoRecordView` objeto usa a troca de dados de caixa de diálogo (DDX) e troca de campos de registro DAO (DFX) para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de registros. `CDaoRecordView` também fornece uma implementação padrão para a movimentação para o primeiro, próximo, anterior ou o último registro e uma interface para atualizar o registro no momento no modo de exibição.

> [!NOTE]
>  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO; as classes DAO geralmente oferecem recursos superiores porque eles usam o mecanismo de banco de dados Microsoft Jet.

É a maneira mais comum para criar a exibição de registro com o Assistente de aplicativo. O Assistente de aplicativo cria a classe de exibição de registro e sua classe de conjunto de registros associado como parte do seu aplicativo de esqueleto starter.

Se você simplesmente precisa de um único formulário, a abordagem do Assistente de aplicativo é mais fácil. ClassWizard permite que você decida usar uma exibição de registro mais tarde no processo de desenvolvimento. Se você não criar a classe de exibição de registro com o Assistente de aplicativo, você pode criá-lo mais tarde com ClassWizard. Usar ClassWizard para criar uma exibição de registro e um conjunto de registros separadamente e, em seguida, conectá-los é a abordagem mais flexível porque isso lhe dará mais controle para nomear a classe de conjunto de registros e seu. H /. Arquivos CPP. Essa abordagem também permite que você tenha vários modos de exibição de registro da mesma classe de conjunto de registros.

Para tornar mais fácil para os usuários finais mover de registro para registro na exibição do registro, o Assistente de aplicativo cria menus (e, opcionalmente, barra de ferramentas) recursos para mover para o primeiro, próximo, anterior ou o último registro. Se você criar uma classe de exibição de registro com ClassWizard, você precisa criar esses recursos por conta própria com o menu e bitmap editores.

Para obter informações sobre a implementação padrão para a movimentação de registro em registro, consulte `IsOnFirstRecord` e `IsOnLastRecord` e o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md), que se aplica a ambos `CRecordView` e `CDaoRecordView`.

`CDaoRecordView` mantém controle da posição do usuário no conjunto de registros, para que o modo de exibição de registro possa atualizar a interface do usuário. Quando o usuário move para ambas as extremidades do conjunto de registros, o modo de exibição do registro desabilita os objetos de interface do usuário — como itens de menu ou botões da barra de ferramentas — para a movimentação adicional na mesma direção.

Para obter mais informações sobre como declarar e usar suas classes de conjunto de registros e a exibição de registro, consulte "Projetando e criando uma exibição do Registro" no artigo [exibições de registro](../../data/record-views-mfc-data-access.md). Para obter mais informações sobre como as exibições de registro de trabalho e como usá-los, consulte o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md). Todos os artigos mencionados acima se aplicam a ambos `CRecordView` e `CDaoRecordView`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CScrollView](../../mfc/reference/cscrollview-class.md)

[CFormView](../../mfc/reference/cformview-class.md)

`CDaoRecordView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

##  <a name="cdaorecordview"></a>  CDaoRecordView::CDaoRecordView

Quando você cria um objeto de um tipo derivado de `CDaoRecordView`, chame o formulário do construtor para inicializar o objeto de exibição e identificar o recurso de caixa de diálogo na qual o modo de exibição se baseia.

```
explicit CDaoRecordView(LPCTSTR lpszTemplateName);
explicit CDaoRecordView(UINT nIDTemplate);
```

### <a name="parameters"></a>Parâmetros

*lpszTemplateName*<br/>
Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.

*nIDTemplate*<br/>
Contém o número de identificação de um recurso de modelo de caixa de diálogo.

### <a name="remarks"></a>Comentários

Ou você pode identificar o recurso por nome (passar uma cadeia de caracteres como o argumento para o construtor) ou por sua ID (um inteiro sem sinal, como o argumento de passagem). Usando um recurso de ID é recomendada.

> [!NOTE]
>  Sua classe derivada deve fornecer seu próprio construtor. No construtor da classe derivada, chame o construtor `CDaoRecordView::CDaoRecordView` com o nome do recurso ou ID como um argumento.

`CDaoRecordView::OnInitialUpdate` chamadas `CWnd::UpdateData`, que chama `CWnd::DoDataExchange`. Essa chamada inicial para `DoDataExchange` se conecta `CDaoRecordView` controla (indiretamente) para `CDaoRecordset` os membros de dados criados por ClassWizard de campo. Esses membros de dados não podem ser usados até depois de chamar a classe base `CFormView::OnInitialUpdate` função de membro.

> [!NOTE]
>  Se você usar ClassWizard, o assistente define uma **enum** valor `CDaoRecordView::IDD` na declaração de classe e usa-o na inicialização do membro lista para o construtor.

[!code-cpp[NVC_MFCDatabase#35](../../mfc/codesnippet/cpp/cdaorecordview-class_1.cpp)]

##  <a name="isonfirstrecord"></a>  CDaoRecordView::IsOnFirstRecord

Chame essa função de membro para determinar se o registro atual é o primeiro registro no objeto recordset associado com este modo de exibição do registro.

```
BOOL IsOnFirstRecord();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o registro atual é o primeiro registro no conjunto de registros; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é útil para escrever suas próprias implementações do padrão escritos por ClassWizard de manipuladores de atualização de comando.

Se o usuário move para o primeiro registro, o desabilita framework objetos de qualquer interface do usuário (por exemplo, itens de menu ou botões da barra de ferramentas) que você tem para mover para o primeiro ou o registro anterior.

##  <a name="isonlastrecord"></a>  CDaoRecordView::IsOnLastRecord

Chame essa função de membro para determinar se o registro atual é o último registro no objeto recordset associado com este modo de exibição do registro.

```
BOOL IsOnLastRecord();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o registro atual é o último registro no conjunto de registros; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é útil para escrever suas próprias implementações do padrão de manipuladores de atualização de comando que grava de ClassWizard para dar suporte a uma interface do usuário para a movimentação de registro para registro.

> [!CAUTION]
>  O resultado dessa função é confiável, exceto que o modo de exibição não pode ser capaz de detectar o fim do conjunto de registros até que o usuário passou para ele. O usuário pode ter se mover além do último registro antes da exibição de registro pode dizer que ele deve desabilitar quaisquer objetos de interface do usuário para a movimentação para o próximo ou último registro. Se o usuário move após o último registro e, em seguida, move de volta para o último registro (ou antes dele), o modo de exibição do registro pode controlar a posição do usuário no conjunto de registros e desativar objetos de interface de usuário corretamente.

##  <a name="ongetrecordset"></a>  CDaoRecordView::OnGetRecordset

Retorna um ponteiro para o `CDaoRecordset`-derivados do objeto associado com o modo de exibição do registro.

```
virtual CDaoRecordset* OnGetRecordset() = 0;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CDaoRecordset`-objeto derivado, se o objeto foi criado com êxito; caso contrário, um ponteiro NULL.

### <a name="remarks"></a>Comentários

Você deve substituir essa função de membro para construir ou obter um objeto de conjunto de registros e retornar um ponteiro para ele. Se você declarar sua classe de exibição de registro com ClassWizard, o assistente grava uma substituição padrão para você. Implementação do padrão do ClassWizard retorna o ponteiro de conjunto de registros armazenado na exibição do registro, se houver. Se não, ele constrói um objeto de conjunto de registros do tipo especificado com ClassWizard e chama seu `Open` membro de função para abrir a tabela ou executar a consulta e, em seguida, retorna um ponteiro para o objeto.

Para obter mais informações e exemplos, consulte o artigo [exibições de registro: usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).

##  <a name="onmove"></a>  CDaoRecordView::OnMove

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

A implementação padrão chama a função de membro Move apropriada do `CDaoRecordset` objeto associado com o modo de exibição do registro.

Por padrão, `OnMove` atualiza o registro atual na fonte de dados se o usuário foi alterado na exibição do registro.

O Assistente de aplicativo cria um recurso de menu com itens de menu do primeiro registro, o último registro, o próximo registro e registro anterior. Se você selecionar a opção de barra de ferramentas inicial, o Assistente de aplicativo também cria uma barra de ferramentas com botões correspondentes a esses comandos.

Se você mover além do último registro no conjunto de registros, o modo de exibição de registro continua a exibir o último registro. Se você mover para trás após o primeiro registro, o modo de exibição de registro continua a exibir o primeiro registro.

> [!CAUTION]
>  Chamar `OnMove` lança uma exceção se o conjunto de registros não tem registros. Chame a função de manipulador de atualização de interface de usuário apropriado — `OnUpdateRecordFirst`, `OnUpdateRecordLast`, `OnUpdateRecordNext`, ou `OnUpdateRecordPrev` — correspondente antes de mover a operação para determinar se o conjunto de registros tem todos os registros.

## <a name="see-also"></a>Consulte também

[Classe CFormView](../../mfc/reference/cformview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)<br/>
[Classe CFormView](../../mfc/reference/cformview-class.md)
