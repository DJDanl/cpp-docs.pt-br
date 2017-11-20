---
title: Classe CDaoRecordView | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDaoRecordView
- AFXDAO/CDaoRecordView
- AFXDAO/CDaoRecordView::CDaoRecordView
- AFXDAO/CDaoRecordView::IsOnFirstRecord
- AFXDAO/CDaoRecordView::IsOnLastRecord
- AFXDAO/CDaoRecordView::OnGetRecordset
- AFXDAO/CDaoRecordView::OnMove
dev_langs: C++
helpviewer_keywords:
- CDaoRecordView [MFC], CDaoRecordView
- CDaoRecordView [MFC], IsOnFirstRecord
- CDaoRecordView [MFC], IsOnLastRecord
- CDaoRecordView [MFC], OnGetRecordset
- CDaoRecordView [MFC], OnMove
ms.assetid: 5aa7d0e2-bd05-413e-b216-80c404ce18ac
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 7ec582c6a5abafebbe6a130cacb7b8d30f571961
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cdaorecordview-class"></a>Classe CDaoRecordView
Uma exibição que mostra os registros do banco de dados em controles.  
  
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
|[CDaoRecordView::IsOnFirstRecord](#isonfirstrecord)|Retorna zero se o registro atual é o primeiro registro no conjunto de registros associado.|  
|[CDaoRecordView::IsOnLastRecord](#isonlastrecord)|Retorna zero se o registro atual é o último registro no conjunto de registros associado.|  
|[CDaoRecordView::OnGetRecordset](#ongetrecordset)|Retorna um ponteiro para um objeto de uma classe derivada de `CDaoRecordset`. ClassWizard substitui essa função para você e cria o conjunto de registros, se necessário.|  
|[CDaoRecordView::OnMove](#onmove)|Se o registro atual foi alterada, atualiza-la na fonte de dados, move para o registro especificado (próximo, anterior, primeiro ou último).|  
  
## <a name="remarks"></a>Comentários  
 A exibição é um modo de exibição de formulário conectado diretamente a um `CDaoRecordset` objeto. A exibição é criada a partir de um recurso de modelo de caixa de diálogo e exibe os campos do `CDaoRecordset` objeto nos controles do modelo de caixa de diálogo. O `CDaoRecordView` objeto usa a troca de dados de caixa de diálogo (DDX) e troca de campos de registro DAO (DFX) para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de registros. `CDaoRecordView`também fornece uma implementação padrão para mover para a primeira, próximo, anterior ou o último registro e uma interface para atualizar o registro no momento no modo de exibição.  
  
> [!NOTE]
>  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO; as classes DAO geralmente oferecem recursos avançados de porque eles usam o mecanismo de banco de dados Microsoft Jet.  
  
 É a maneira mais comum para criar a exibição de registro com o Assistente de aplicativo. O Assistente de aplicativo cria a classe de exibição de registro e sua classe de conjunto de registros associado como parte do seu aplicativo de esqueleto starter.  
  
 Se você precisar apenas uma única forma, a abordagem de Assistente de aplicativo é mais fácil. ClassWizard permite que você decidir usar um modo de exibição de registro mais tarde no processo de desenvolvimento. Se você não criar a classe de exibição de registro com o Assistente de aplicativo, você pode criá-lo mais tarde com ClassWizard. Usando ClassWizard para criar uma exibição de registro e um conjunto de registros separadamente e, em seguida, conectá-los é a abordagem mais flexível, pois ele oferece mais controle para a classe de conjunto de registros de nomenclatura e sua. H /. Arquivos CPP. Essa abordagem também permite que você tenha várias exibições de registro na mesma classe de conjunto de registros.  
  
 Para facilitar para os usuários finais mover de registro para registro no modo de exibição de registro, o Assistente de aplicativo cria menu (e, opcionalmente, barra de ferramentas) recursos para mover para a primeira, próximo, anterior ou o último registro. Se você criar uma classe de exibição de registro com ClassWizard, você precisa criar esses recursos por conta própria com o menu e bitmap editores.  
  
 Para obter informações sobre a implementação do padrão para a movimentação de um registro para o registro, consulte `IsOnFirstRecord` e `IsOnLastRecord` e o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md), que se aplica a ambos `CRecordView` e `CDaoRecordView`.  
  
 `CDaoRecordView`Controla de posição do usuário no conjunto de registros para que o modo de exibição de registro possa atualizar a interface do usuário. Quando o usuário move para o fim do conjunto de registros, o modo de exibição de registro desabilita os objetos de interface do usuário — como itens de menu ou botões da barra de ferramentas — para mover adicional na mesma direção.  
  
 Para obter mais informações sobre como declarar e usar suas classes de conjunto de registros e a exibição de registro, consulte "Projetando e criando uma exibição de registro" no artigo [exibições de registro](../../data/record-views-mfc-data-access.md). Para obter mais informações sobre como as exibições de registro de trabalho e como usá-los, consulte o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md). Todos os artigos mencionados acima se aplicam a ambos `CRecordView` e `CDaoRecordView`.  
  
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
  
##  <a name="cdaorecordview"></a>CDaoRecordView::CDaoRecordView  
 Quando você cria um objeto de um tipo derivado de `CDaoRecordView`, chame qualquer formulário de construtor para inicializar o objeto de exibição e identificar o recurso de caixa de diálogo na qual a exibição é baseada.  
  
```  
explicit CDaoRecordView(LPCTSTR lpszTemplateName);  
explicit CDaoRecordView(UINT nIDTemplate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszTemplateName`  
 Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.  
  
 `nIDTemplate`  
 Contém o número de identificação de um recurso de modelo de caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Ou você pode identificar os recursos por nome (passar uma cadeia de caracteres como o argumento para o construtor) ou por sua ID (um inteiro sem sinal, como o argumento de passagem). Usando um recurso ID é recomendada.  
  
> [!NOTE]
>  A classe derivada deve fornecer seu próprio construtor. No construtor de classe derivada, chame o construtor `CDaoRecordView::CDaoRecordView` com o nome do recurso ou a ID como um argumento.  
  
 **CDaoRecordView::OnInitialUpdate** chamadas `CWnd::UpdateData`, que chama `CWnd::DoDataExchange`. Essa chamada inicial para `DoDataExchange` conecta `CDaoRecordView` controla (indiretamente) ao `CDaoRecordset` campo membros de dados criados por ClassWizard. Esses membros de dados não podem ser usados até depois de chamar a classe base **CFormView::OnInitialUpdate** função de membro.  
  
> [!NOTE]
>  Se você usar ClassWizard, o assistente define uma `enum` valor `CDaoRecordView::IDD` na declaração de classe e usa-o na inicialização de membro lista do construtor.  
  
 [!code-cpp[NVC_MFCDatabase#35](../../mfc/codesnippet/cpp/cdaorecordview-class_1.cpp)]  
  
##  <a name="isonfirstrecord"></a>CDaoRecordView::IsOnFirstRecord  
 Chame essa função de membro para determinar se o registro atual é o primeiro registro no objeto recordset associado a este modo de exibição do registro.  
  
```  
BOOL IsOnFirstRecord();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o registro atual é o primeiro registro no conjunto de registros; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é útil para escrever suas próprias implementações do padrão escritos por ClassWizard manipuladores de atualização de comando.  
  
 Se o usuário move para o primeiro registro, o desabilita framework objetos, nenhuma interface do usuário (por exemplo, itens de menu ou botões da barra de ferramentas) que você tem para mover para o primeiro ou o registro anterior.  
  
##  <a name="isonlastrecord"></a>CDaoRecordView::IsOnLastRecord  
 Chame essa função de membro para determinar se o registro atual é o último registro no objeto recordset associado a este modo de exibição do registro.  
  
```  
BOOL IsOnLastRecord();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o registro atual é o último registro no conjunto de registros; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é útil para escrever suas próprias implementações do padrão manipuladores de atualização de comando que grava ClassWizard para dar suporte a uma interface do usuário para a movimentação de um registro para outro.  
  
> [!CAUTION]
>  O resultado dessa função é confiável, exceto que o modo de exibição não pode ser capaz de detectar o final do conjunto de registros até que o usuário passou para ele. O usuário talvez precise mover além do último registro antes que a exibição de registro pode dizer que ele deve desabilitar quaisquer objetos de interface do usuário para mover para o próximo ou o último registro. Se o usuário ultrapassar o último registro e, em seguida, volta para o último registro (ou antes dele), o modo de exibição de registro pode controlar a posição do usuário no conjunto de registros e desabilitar os objetos de interface de usuário corretamente.  
  
##  <a name="ongetrecordset"></a>CDaoRecordView::OnGetRecordset  
 Retorna um ponteiro para o `CDaoRecordset`-derivados do objeto associado à exibição de registro.  
  
```  
virtual CDaoRecordset* OnGetRecordset() = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CDaoRecordset`-objeto derivado se o objeto foi criado com êxito; caso contrário, um **nulo** ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Você deve substituir esta função de membro para criar ou obter um objeto de conjunto de registros e retornar um ponteiro para ele. Se você declarar a classe de exibição de registro com ClassWizard, o assistente grava uma substituição padrão para você. Implementação do padrão do ClassWizard retorna o ponteiro de conjunto de registros armazenado na exibição do registro, se houver. Se não, ele constrói um objeto de conjunto de registros do tipo especificado com ClassWizard e chama seu **abrir** membro de função para abrir a tabela ou executar a consulta e, em seguida, retorna um ponteiro para o objeto.  
  
 Para obter mais informações e exemplos, consulte o artigo [exibições de registro: usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).  
  
##  <a name="onmove"></a>CDaoRecordView::OnMove  
 Chame essa função de membro para mover para um registro diferente no conjunto de registros e exibir seus campos dos controles de exibição de registro.  
  
```  
virtual BOOL OnMove(UINT nIDMoveCommand);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDMoveCommand`  
 Um dos seguintes valores de ID de comando padrão:  
  
- `ID_RECORD_FIRST`Mover para o primeiro registro no conjunto de registros.  
  
- `ID_RECORD_LAST`Mova para o último registro no conjunto de registros.  
  
- `ID_RECORD_NEXT`Mover para o próximo registro no conjunto de registros.  
  
- `ID_RECORD_PREV`Mover para o registro anterior no conjunto de registros.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a movimentação foi bem-sucedida; Caso contrário, 0 se a solicitação de movimentação foi negada.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão chama a função de membro mover apropriada do `CDaoRecordset` objeto associado à exibição de registro.  
  
 Por padrão, `OnMove` atualiza o registro atual na fonte de dados se o usuário alterou na exibição do registro.  
  
 O Assistente de aplicativo cria um recurso de menu com itens de menu do primeiro registro, último registro, próximo registro e registro anterior. Se você selecionar a opção de barra de ferramentas inicial, o Assistente de aplicativo também cria uma barra de ferramentas com botões correspondentes a esses comandos.  
  
 Se você mover além do último registro no conjunto de registros, o modo de exibição de registro continua a exibir o último registro. Se você retroceder após o primeiro registro, o modo de exibição de registro continua a exibir o primeiro registro.  
  
> [!CAUTION]
>  Chamando `OnMove` lança uma exceção se o conjunto de registros não contém registros. Chame a função de manipulador de atualização de interface de usuário apropriado — **OnUpdateRecordFirst**, **OnUpdateRecordLast**, **OnUpdateRecordNext**, ou  **OnUpdateRecordPrev** — correspondente antes de operação de movimentação para determinar se o conjunto de registros tem todos os registros.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFormView](../../mfc/reference/cformview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)   
 [Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)   
 [Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)   
 [Classe CFormView](../../mfc/reference/cformview-class.md)
