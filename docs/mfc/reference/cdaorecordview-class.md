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
ms.openlocfilehash: b8c411dbd29316219759351f1f1633b6e57b92e8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377138"
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
|[CDaoRecordView::IsOnFirstRecord](#isonfirstrecord)|Retorna não zero se o registro atual for o primeiro registro no conjunto de registros associados.|
|[CDaoRecordView::IsOnLastRecord](#isonlastrecord)|Retorna não zero se o registro atual for o último registro no conjunto de registros associados.|
|[CDaoRecordView::OnGetRecordset](#ongetrecordset)|Retorna um ponteiro para um objeto `CDaoRecordset`de uma classe derivada de . ClassWizard substitui essa função para você e cria o conjunto de registros, se necessário.|
|[CDaoRecordView::OnMove](#onmove)|Se o registro atual tiver sido alterado, atualize-o na fonte de dados e, em seguida, passa para o registro especificado (próximo, anterior, primeiro ou último).|

## <a name="remarks"></a>Comentários

A exibição é uma exibição de formulário diretamente conectada a um `CDaoRecordset` objeto. A exibição é criada a partir de um `CDaoRecordset` recurso de modelo de diálogo e exibe os campos do objeto nos controles do modelo de diálogo. O `CDaoRecordView` objeto usa o DDX (Exchange de dados de diálogo) e o DFX (Dao record field exchange) para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de registros. `CDaoRecordView`também fornece uma implementação padrão para mover para o primeiro, próximo, anterior ou último registro e uma interface para atualizar o registro atualmente em exibição.

> [!NOTE]
> As classes de banco de dados DAO são distintas das classes de banco de dados MFC baseadas em Conectividade de Banco de Dados Aberto (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados oDBC com as classes DAO; as classes DAO geralmente oferecem recursos superiores porque usam o mecanismo de banco de dados Microsoft Jet.

A maneira mais comum de criar sua visualização de registro é com o Assistente de Aplicativos. O Assistente de aplicativo cria a classe de exibição de registro e sua classe de conjunto de registros associada como parte do aplicativo de inicialização do esqueleto.

Se você simplesmente precisar de um único formulário, a abordagem do Assistente de Aplicativo é mais fácil. O ClassWizard permite que você decida usar uma exibição de registro mais tarde no processo de desenvolvimento. Se você não criar a classe de exibição de registro com o Assistente de aplicativo, poderá criá-la mais tarde com o ClassWizard. Usar o ClassWizard para criar uma exibição de registro e um conjunto de registros separadamente e, em seguida, conectá-los é a abordagem mais flexível porque lhe dá mais controle na nomeação da classe recordset e sua . H/. Arquivos CPP. Essa abordagem também permite que você tenha várias visualizações de registro na mesma classe de conjunto de discos.

Para facilitar a mudança dos usuários finais do registro para o registro na exibição de registro, o Assistente de aplicativo cria recursos de menu (e, opcionalmente, barra de ferramentas) para mover para o primeiro, próximo, anterior ou último registro. Se você criar uma classe de exibição de gravação com o ClassWizard, você mesmo precisará criar esses recursos com os editores de menu e bitmap.

Para obter informações sobre a implementação padrão `IsOnFirstRecord` `IsOnLastRecord` para passar de registro para registro, `CRecordView` veja `CDaoRecordView`e e o artigo Usando [uma exibição de registro,](../../data/using-a-record-view-mfc-data-access.md)que se aplica a ambos e .

`CDaoRecordView`mantém o controle da posição do usuário no conjunto de registros para que a visualização de registro possa atualizar a interface do usuário. Quando o usuário se move para o fim do conjunto de registros, a visualização de registro desativa objetos de interface do usuário — como itens de menu ou botões de barra de ferramentas — para se mover mais na mesma direção.

Para obter mais informações sobre como declarar e usar suas classes de exibição de registro e conjunto de registros, consulte "Projetando e Criando uma Exibição de Registro" no artigo [Record Views](../../data/record-views-mfc-data-access.md). Para obter mais informações sobre como as visualizações de registros funcionam e como usá-las, consulte o artigo [Usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md). Todos os artigos mencionados `CRecordView` `CDaoRecordView`acima aplicam-se a ambos e .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CScrollView](../../mfc/reference/cscrollview-class.md)

[CFormView](../../mfc/reference/cformview-class.md)

`CDaoRecordView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="cdaorecordviewcdaorecordview"></a><a name="cdaorecordview"></a>CDaoRecordView::CDaoRecordView

Quando você criar um objeto de `CDaoRecordView`um tipo derivado, chame qualquer forma do construtor para inicializar o objeto de exibição e identificar o recurso de diálogo no qual a exibição é baseada.

```
explicit CDaoRecordView(LPCTSTR lpszTemplateName);
explicit CDaoRecordView(UINT nIDTemplate);
```

### <a name="parameters"></a>Parâmetros

*lpszTemplateName*<br/>
Contém uma seqüência de seqüência de terminadas nula que é o nome de um recurso de modelo de diálogo.

*Nidtemplate*<br/>
Contém o número de ID de um recurso de modelo de diálogo.

### <a name="remarks"></a>Comentários

Você pode identificar o recurso por nome (passar uma string como argumento para o construtor) ou pelo seu ID (passar um inteiro não assinado como argumento). Recomenda-se o uso de um ID de recurso.

> [!NOTE]
> Sua classe derivada deve fornecer seu próprio construtor. Na construtora de sua classe derivada, `CDaoRecordView::CDaoRecordView` chame o construtor com o nome do recurso ou ID como argumento.

`CDaoRecordView::OnInitialUpdate`chamadas, `CWnd::UpdateData`que `CWnd::DoDataExchange`chama . Esta chamada `DoDataExchange` inicial `CDaoRecordView` para conectar controles (indiretamente) a `CDaoRecordset` membros de dados de campo criados pelo ClassWizard. Esses membros de dados não podem ser `CFormView::OnInitialUpdate` usados até depois de chamar a função de membro da classe base.

> [!NOTE]
> Se você usar o ClassWizard, o `CDaoRecordView::IDD` assistente definirá um valor **de enum** na declaração de classe e o usará na lista de inicialização de membros para o construtor.

[!code-cpp[NVC_MFCDatabase#35](../../mfc/codesnippet/cpp/cdaorecordview-class_1.cpp)]

## <a name="cdaorecordviewisonfirstrecord"></a><a name="isonfirstrecord"></a>CDaoRecordView::IsOnFirstRecord

Ligue para esta função de membro para determinar se o registro atual é o primeiro registro no objeto recordset associado a essa exibição de registro.

```
BOOL IsOnFirstRecord();
```

### <a name="return-value"></a>Valor retornado

Não zero se o registro atual é o primeiro registro no conjunto de discos; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função é útil para escrever suas próprias implementações dos manipuladores de atualização de comando padrão escritos pelo ClassWizard.

Se o usuário se mover para o primeiro registro, a estrutura desativará quaisquer objetos de interface do usuário (por exemplo, itens de menu ou botões de barra de ferramentas) que você tem para mover para o primeiro ou o registro anterior.

## <a name="cdaorecordviewisonlastrecord"></a><a name="isonlastrecord"></a>CDaoRecordView::IsOnLastRecord

Ligue para esta função de membro para determinar se o registro atual é o último registro no objeto recordset associado a essa exibição de registro.

```
BOOL IsOnLastRecord();
```

### <a name="return-value"></a>Valor retornado

Não zero se o registro atual for o último registro no conjunto de registros; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função é útil para escrever suas próprias implementações dos manipuladores de atualização de comando padrão que o ClassWizard escreve para suportar uma interface de usuário para passar de registro para registro.

> [!CAUTION]
> O resultado desta função é confiável, exceto que a exibição pode não ser capaz de detectar o fim do conjunto de registros até que o usuário tenha passado por ela. O usuário pode ter que passar além do último registro antes que a visualização de registro possa dizer que deve desativar quaisquer objetos de interface do usuário para mover-se para o próximo ou último registro. Se o usuário passar o último registro e depois voltar para o último registro (ou antes dele), a visualização de registro poderá rastrear a posição do usuário no conjunto de registros e desativar os objetos da interface do usuário corretamente.

## <a name="cdaorecordviewongetrecordset"></a><a name="ongetrecordset"></a>CDaoRecordView::OnGetRecordset

Retorna um ponteiro `CDaoRecordset`para o objeto derivado associado à exibição de registro.

```
virtual CDaoRecordset* OnGetRecordset() = 0;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `CDaoRecordset`para um objeto derivado se o objeto foi criado com sucesso; caso contrário, um ponteiro NULL.

### <a name="remarks"></a>Comentários

Você deve substituir esta função de membro para construir ou obter um objeto de conjunto de registros e retornar um ponteiro para ele. Se você declarar sua classe de exibição de gravação com o ClassWizard, o assistente escreverá uma substituição padrão para você. A implementação padrão do ClassWizard retorna o ponteiro de conjunto de registros armazenado na exibição de registro, se existir. Se não, ele constrói um objeto de conjunto de registros do `Open` tipo especificado com o ClassWizard e chama sua função de membro para abrir a tabela ou executar a consulta e, em seguida, retorna um ponteiro para o objeto.

Para obter mais informações e exemplos, consulte o artigo [Record Views: Usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).

## <a name="cdaorecordviewonmove"></a><a name="onmove"></a>CDaoRecordView::OnMove

Chame esta função de membro para mover para um registro diferente no conjunto de registros e exibir seus campos nos controles da exibição de registro.

```
virtual BOOL OnMove(UINT nIDMoveCommand);
```

### <a name="parameters"></a>Parâmetros

*nIDMoveCommand*<br/>
Um dos seguintes valores de ID de comando padrão:

- ID_RECORD_FIRST passar para o primeiro disco no conjunto de discos.

- ID_RECORD_LAST passar para o último disco no conjunto de discos.

- ID_RECORD_NEXT passar para o próximo disco no conjunto de discos.

- ID_RECORD_PREV passar para o recorde anterior no conjunto de discos.

### <a name="return-value"></a>Valor retornado

Não zero se a mudança foi bem sucedida; caso contrário 0 se o pedido de mudança foi negado.

### <a name="remarks"></a>Comentários

A implementação padrão chama a `CDaoRecordset` função de membro Mover apropriada do objeto associado à exibição de registro.

Por padrão, `OnMove` atualiza o registro atual na fonte de dados se o usuário o alterou na exibição de registro.

O Assistente de aplicativo cria um recurso de menu com itens de menu Primeiro Registro, Último Registro, Próximo Registro e Registro Anterior. Se você selecionar a opção Barra de Ferramentas Inicial, o Assistente de aplicativo também criará uma barra de ferramentas com botões correspondentes a esses comandos.

Se você passar do último registro no conjunto de discos, a exibição de discos continuará a exibir o último registro. Se você passar para trás após o primeiro registro, a visualização de registro continua a exibir o primeiro registro.

> [!CAUTION]
> Chamar `OnMove` abre uma exceção se o conjunto de discos não tiver registros. Ligue para a função de `OnUpdateRecordFirst` `OnUpdateRecordLast`manipulador `OnUpdateRecordNext`de `OnUpdateRecordPrev` atualização de interface de usuário apropriada — ou — antes da operação de movimento correspondente para determinar se o conjunto de registros possui algum registro.

## <a name="see-also"></a>Confira também

[Classe CFormView](../../mfc/reference/cformview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)<br/>
[Classe CFormView](../../mfc/reference/cformview-class.md)
