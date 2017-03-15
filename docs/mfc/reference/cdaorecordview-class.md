---
title: Classe CDaoRecordView | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDaoRecordView
dev_langs:
- C++
helpviewer_keywords:
- CDaoRecordView class
- data-bound controls [C++], DAO controls
- data binding [C++], DAO views
- bound controls [C++], displaying database data
- application wizards [C++], creating record views
- controls [MFC], data binding
ms.assetid: 5aa7d0e2-bd05-413e-b216-80c404ce18ac
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
ms.openlocfilehash: 11aa318e84e89835ceb710725590f3c3e6387fcd
ms.lasthandoff: 02/25/2017

---
# <a name="cdaorecordview-class"></a>Classe CDaoRecordView
Um modo de exibição que exibe registros de banco de dados em controles.  
  
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
|[CDaoRecordView::IsOnFirstRecord](#isonfirstrecord)|Retorna zero se o registro atual for o primeiro registro no conjunto de registros associado.|  
|[CDaoRecordView::IsOnLastRecord](#isonlastrecord)|Retorna zero se o registro atual é o último registro no conjunto de registros associado.|  
|[CDaoRecordView::OnGetRecordset](#ongetrecordset)|Retorna um ponteiro para um objeto de uma classe derivada de `CDaoRecordset`. ClassWizard substitui essa função para você e criará o conjunto de registros, se necessário.|  
|[CDaoRecordView::OnMove](#onmove)|Se o registro atual foi alterado, o atualiza na fonte de dados, move para o registro especificado (próximo, anterior, primeiro ou último).|  
  
## <a name="remarks"></a>Comentários  
 A exibição é um modo de exibição de formulário conectado diretamente a um `CDaoRecordset` objeto. O modo de exibição é criado a partir de um recurso de modelo de caixa de diálogo e exibe os campos do `CDaoRecordset` objeto nos controles do modelo de caixa de diálogo. O `CDaoRecordView` objeto usa a troca de dados de caixa de diálogo (DDX) e troca de campos de registro DAO (DFX) para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de registros. `CDaoRecordView`também fornece uma implementação padrão para mover para o primeiro, próximo, anterior ou o último registro e uma interface para atualizar o registro no momento no modo de exibição.  
  
> [!NOTE]
>  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO; as classes DAO geralmente oferecem recursos avançados de porque eles usam o mecanismo de banco de dados Microsoft Jet.  
  
 É a maneira mais comum de criar seu modo de exibição do registro com o Assistente de aplicativo. O Assistente de aplicativo cria a classe de exibição de registro e sua classe de conjunto de registros associado como parte do seu aplicativo de esqueleto inicial.  
  
 Se você simplesmente precisar de um único formulário, a abordagem do Assistente de aplicativo é mais fácil. ClassWizard permite que você decida usar uma exibição de registro mais tarde no processo de desenvolvimento. Se você não criar a classe de exibição de registro com o Assistente de aplicativo, você pode criá-lo mais tarde com ClassWizard. Usar ClassWizard para criar uma exibição de registro e um conjunto de registros separadamente e, em seguida, conectá-los é a abordagem mais flexível porque isso lhe dá mais controle ao nomear a classe de conjunto de registros e sua. H /. Arquivos CPP. Essa abordagem permite ter várias exibições de registro da mesma classe de conjunto de registros.  
  
 Para tornar mais fácil para os usuários finais mover de um registro para outro na exibição do registro, o Assistente para aplicativo cria menus (e, opcionalmente, barra de ferramentas) recursos para mover para o primeiro, próximo, anterior ou o último registro. Se você criar uma classe de exibição de registro com ClassWizard, você precisa criar esses recursos por conta própria com o menu e bitmap editores.  
  
 Para obter informações sobre a implementação padrão para a movimentação de registro em registro, consulte `IsOnFirstRecord` e `IsOnLastRecord` e o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md), que se aplica a ambos `CRecordView` e `CDaoRecordView`.  
  
 `CDaoRecordView`Controla de posição do usuário no conjunto de registros para que a exibição do registro pode atualizar a interface do usuário. Quando o usuário move para o fim do conjunto de registros, a exibição do registro desabilita os objetos de interface do usuário — como itens de menu ou botões da barra de ferramentas — para mover adicional na mesma direção.  
  
 Para obter mais informações sobre como declarar e usar sua exibição de registro e classes de conjunto de registros, consulte "Projetando e criando uma exibição do Registro" no artigo [exibições de registro](../../data/record-views-mfc-data-access.md). Para obter mais informações sobre como as exibições de registro de trabalho e como usá-los, consulte o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md). Todos os artigos mencionados acima se aplicam a ambos `CRecordView` e `CDaoRecordView`.  
  
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
  
##  <a name="a-namecdaorecordviewa--cdaorecordviewcdaorecordview"></a><a name="cdaorecordview"></a>CDaoRecordView::CDaoRecordView  
 Quando você cria um objeto de um tipo derivado de `CDaoRecordView`, chamar qualquer formulário do construtor para inicializar o objeto de exibição e identificar o recurso de caixa de diálogo na qual a exibição será baseada.  
  
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
 Ou você pode identificar os recursos por nome (passar uma cadeia de caracteres como argumento para o construtor) ou pela sua ID (um inteiro não assinado como o argumento de passagem). Usando um recurso ID é recomendada.  
  
> [!NOTE]
>  Sua classe derivada deve fornecer seu próprio construtor. No construtor da sua classe derivada, chame o construtor `CDaoRecordView::CDaoRecordView` com o nome do recurso ou ID como um argumento.  
  
 **CDaoRecordView::OnInitialUpdate** chamadas `CWnd::UpdateData`, que chama `CWnd::DoDataExchange`. Essa chamada inicial para `DoDataExchange` conecta `CDaoRecordView` (indiretamente) para controles `CDaoRecordset` campo membros de dados criados por ClassWizard. Esses membros de dados não podem ser usados até depois de você chamar a classe base **CFormView::OnInitialUpdate** função de membro.  
  
> [!NOTE]
>  Se você usar ClassWizard, o assistente define uma `enum` valor `CDaoRecordView::IDD` da declaração de classe e o usa na inicialização do membro de lista para o construtor.  
  
 [!code-cpp[NVC_MFCDatabase&#35;](../../mfc/codesnippet/cpp/cdaorecordview-class_1.cpp)]  
  
##  <a name="a-nameisonfirstrecorda--cdaorecordviewisonfirstrecord"></a><a name="isonfirstrecord"></a>CDaoRecordView::IsOnFirstRecord  
 Chame essa função de membro para determinar se o registro atual é o primeiro registro no objeto recordset associado a este modo de exibição do registro.  
  
```  
BOOL IsOnFirstRecord();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o registro atual é o primeiro registro no conjunto de registros; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é útil para escrever suas próprias implementações do padrão manipuladores de atualização de comando escritos por ClassWizard.  
  
 Se o usuário move para o primeiro registro, desabilita o framework que objetos de qualquer interface do usuário (por exemplo, itens de menu ou botões da barra de ferramentas) que você tem para mover para o primeiro ou o registro anterior.  
  
##  <a name="a-nameisonlastrecorda--cdaorecordviewisonlastrecord"></a><a name="isonlastrecord"></a>CDaoRecordView::IsOnLastRecord  
 Chame essa função de membro para determinar se o registro atual é o último registro no objeto recordset associado a este modo de exibição do registro.  
  
```  
BOOL IsOnLastRecord();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o registro atual é o último registro no conjunto de registros; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é útil para escrever suas próprias implementações do padrão manipuladores de atualização de comando que grava ClassWizard para oferecer suporte a uma interface do usuário para mover de um registro para outro.  
  
> [!CAUTION]
>  O resultado dessa função é confiável, exceto que a exibição não poderá detectar o fim do conjunto de registros até que o usuário ter sido movido após ele. O usuário talvez precise ir além do último registro para a exibição de registro pode dizer que ele desative quaisquer objetos de interface do usuário para mover para o próximo ou o último registro. Se o usuário ultrapassar o último registro e, em seguida, volte para o último registro (ou anterior), a exibição do registro pode rastrear a posição do usuário no conjunto de registros e desativar objetos de interface de usuário corretamente.  
  
##  <a name="a-nameongetrecordseta--cdaorecordviewongetrecordset"></a><a name="ongetrecordset"></a>CDaoRecordView::OnGetRecordset  
 Retorna um ponteiro para o `CDaoRecordset`-derivados do objeto associado com a exibição do registro.  
  
```  
virtual CDaoRecordset* OnGetRecordset() = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CDaoRecordset`-objeto derivado se o objeto foi com êxito criado; caso contrário, uma **nulo** ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Você deve substituir essa função de membro para construir ou obter um objeto recordset e retornar um ponteiro para ele. Se você declarar a classe de exibição de registro com ClassWizard, o assistente grava uma substituição padrão para você. Implementação do padrão do ClassWizard retorna o ponteiro de conjunto de registros armazenado na exibição do registro, se houver. Se não, ele constrói um objeto de conjunto de registros do tipo especificado com ClassWizard e chama seu **abrir** membro de função para abrir a tabela ou executar a consulta e, em seguida, retorna um ponteiro para o objeto.  
  
 Para obter mais informações e exemplos, consulte o artigo [exibições de registro: usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).  
  
##  <a name="a-nameonmovea--cdaorecordviewonmove"></a><a name="onmove"></a>CDaoRecordView::OnMove  
 Chame essa função de membro para mover para um registro diferente no conjunto de registros e exibir os seus campos nos controles de exibição do registro.  
  
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
 A implementação padrão chama a função de membro Move apropriada do `CDaoRecordset` objeto associado com a exibição do registro.  
  
 Por padrão, `OnMove` atualiza o registro atual na fonte de dados se o usuário alterou na exibição do registro.  
  
 O Assistente para aplicativo cria um recurso de menu com itens de menu do primeiro registro, último registro, próximo registro e registro anterior. Se você selecionar a opção de barra de ferramentas inicial, o Assistente de aplicativo também cria uma barra de ferramentas com botões correspondentes a esses comandos.  
  
 Se você mover além do último registro no conjunto de registros, o modo de exibição de registro continua a exibir o último registro. Se você voltar após o primeiro registro, o modo de exibição de registro continua a exibir o primeiro registro.  
  
> [!CAUTION]
>  Chamando `OnMove` lança uma exceção se o conjunto de registros não contém registros. Chamar a função de manipulador de atualização do usuário apropriada interface — **OnUpdateRecordFirst**, **OnUpdateRecordLast**, **OnUpdateRecordNext**, ou **OnUpdateRecordPrev** — correspondente antes de mover a operação para determinar se o conjunto de registros tem todos os registros.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFormView](../../mfc/reference/cformview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)   
 [Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)   
 [Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)   
 [Classe CFormView](../../mfc/reference/cformview-class.md)

