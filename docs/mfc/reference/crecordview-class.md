---
title: Classe CRecordView | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRecordView
- AFXDB/CRecordView
- AFXDB/CRecordView::CRecordView
- AFXDB/CRecordView::IsOnFirstRecord
- AFXDB/CRecordView::IsOnLastRecord
- AFXDB/CRecordView::OnGetRecordset
- AFXDB/CRecordView::OnMove
- AFXDB/CRecordView::OnMove
dev_langs:
- C++
helpviewer_keywords:
- CRecordView class
- ODBC recordsets, viewing records
- records, viewing ODBC
- views, ODBC
ms.assetid: 9b4b0897-bd50-4d48-a0b4-f3323f5ccc55
caps.latest.revision: 25
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 04ff47900037dcbaa12e2cba2c9a3e84caf54a69
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="crecordview-class"></a>Classe CRecordView
Um modo de exibição que exibe registros de banco de dados em controles.  
  
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
|[CRecordView::IsOnFirstRecord](#isonfirstrecord)|Retorna zero se o registro atual for o primeiro registro no conjunto de registros associado.|  
|[CRecordView::IsOnLastRecord](#isonlastrecord)|Retorna zero se o registro atual é o último registro no conjunto de registros associado.|  
|[CRecordView::OnGetRecordset](#ongetrecordset)|Retorna um ponteiro para um objeto de uma classe derivada de `CRecordset`. ClassWizard substitui essa função para você e criará o conjunto de registros, se necessário.|  
|[CRecordView::OnMove](#onmove)||  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRecordView::OnMove](#onmove)|Se o registro atual foi alterado, o atualiza na fonte de dados, move para o registro especificado (próximo, anterior, primeiro ou último).|  
  
## <a name="remarks"></a>Comentários  
 A exibição é um modo de exibição de formulário conectado diretamente a um `CRecordset` objeto. O modo de exibição é criado a partir de um recurso de modelo de caixa de diálogo e exibe os campos do `CRecordset` objeto nos controles do modelo de caixa de diálogo. O `CRecordView` objeto usa a troca de dados de caixa de diálogo (DDX) e troca de campos de registro (RFX) para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de registros. `CRecordView`também fornece uma implementação padrão para mover para o primeiro, próximo, anterior ou o último registro e uma interface para atualizar o registro no momento no modo de exibição.  
  
> [!NOTE]
>  Se você estiver trabalhando com as classes de objetos de acesso de dados (DAO) em vez das classes de conectividade de banco de dados aberto (ODBC), use a classe [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) em vez disso. Para obter mais informações, consulte o artigo [visão geral: programação do banco de dados](../../data/data-access-programming-mfc-atl.md).  
  
 É a maneira mais comum de criar seu modo de exibição do registro com o Assistente de aplicativo. Assistente de aplicativo Tge cria a classe de exibição de registro e sua classe de conjunto de registros associado como parte do seu aplicativo de esqueleto inicial. Se você não criar a classe de exibição de registro com o Assistente de aplicativo, você pode criá-lo mais tarde com ClassWizard. Se você simplesmente precisar de um único formulário, a abordagem do Assistente de aplicativo é mais fácil. ClassWizard permite que você decida usar uma exibição de registro mais tarde no processo de desenvolvimento. Usar ClassWizard para criar uma exibição de registro e um conjunto de registros separadamente e, em seguida, conectá-los é a abordagem mais flexível porque isso lhe dá mais controle ao nomear a classe de conjunto de registros e sua. H /. Arquivos CPP. Essa abordagem permite ter várias exibições de registro da mesma classe de conjunto de registros.  
  
 Para tornar mais fácil para os usuários finais mover de um registro para outro na exibição do registro, o Assistente para aplicativo cria menus (e, opcionalmente, barra de ferramentas) recursos para mover para o primeiro, próximo, anterior ou o último registro. Se você criar uma classe de exibição de registro com ClassWizard, você precisa criar esses recursos por conta própria com o menu e bitmap editores.  
  
 Para obter informações sobre a implementação padrão para a movimentação de registro em registro, consulte `IsOnFirstRecord` e `IsOnLastRecord` e o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).  
  
 `CRecordView`Controla de posição do usuário no conjunto de registros para que a exibição do registro pode atualizar a interface do usuário. Quando o usuário move para o fim do conjunto de registros, a exibição do registro desabilita os objetos de interface do usuário — como itens de menu ou botões da barra de ferramentas — para mover adicional na mesma direção.  
  
 Para obter mais informações sobre como declarar e usar sua exibição de registro e classes de conjunto de registros, consulte "Projetando e criando uma exibição do Registro" no artigo [exibições de registro](../../data/record-views-mfc-data-access.md). Para obter mais informações sobre como as exibições de registro de trabalho e como usá-los, consulte o artigo [usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).  
  
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
  
##  <a name="crecordview"></a>CRecordView::CRecordView  
 Quando você cria um objeto de um tipo derivado de `CRecordView`, chamar qualquer formulário do construtor para inicializar o objeto de exibição e identificar o recurso de caixa de diálogo na qual a exibição será baseada.  
  
```  
explicit CRecordView(LPCTSTR lpszTemplateName);  
explicit CRecordView(UINT nIDTemplate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszTemplateName`  
 Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.  
  
 `nIDTemplate`  
 Contém o número de identificação de um recurso de modelo de caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Ou você pode identificar os recursos por nome (passar uma cadeia de caracteres como argumento para o construtor) ou pela sua ID (um inteiro não assinado como o argumento de passagem). Usando um recurso ID é recomendada.  
  
> [!NOTE]
>  Sua classe derivada *deve* fornecer seu próprio construtor. No construtor da sua classe derivada, chame o construtor `CRecordView::CRecordView` com o nome do recurso ou ID como um argumento, como mostrado no exemplo a seguir.  
  
 **CRecordView::OnInitialUpdate** chamadas `UpdateData`, que chama `DoDataExchange`. Essa chamada inicial para `DoDataExchange` conecta `CRecordView` (indiretamente) para controles `CRecordset` campo membros de dados criados por ClassWizard. Esses membros de dados não podem ser usados até depois de você chamar a classe base **CFormView::OnInitialUpdate** função de membro.  
  
> [!NOTE]
>  Se você usar ClassWizard, o assistente define uma `enum` valor `CRecordView::IDD`, especifica-lo na declaração da classe e usa-lo na lista de inicialização de membros para o construtor.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[32 NVC_MFCDatabase](../../mfc/codesnippet/cpp/crecordview-class_1.cpp)]  
  
##  <a name="isonfirstrecord"></a>CRecordView::IsOnFirstRecord  
 Chame essa função de membro para determinar se o registro atual é o primeiro registro no objeto recordset associado a este modo de exibição do registro.  
  
```  
BOOL IsOnFirstRecord();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o registro atual é o primeiro registro no conjunto de registros; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é útil para escrever suas próprias implementações padrão manipuladores de atualização de comando escritos por ClassWizard.  
  
 Se o usuário move para o primeiro registro, o framework desativa quaisquer objetos de interface de usuário para mover para o primeiro ou o registro anterior.  
  
##  <a name="isonlastrecord"></a>CRecordView::IsOnLastRecord  
 Chame essa função de membro para determinar se o registro atual é o último registro no objeto recordset associado a este modo de exibição do registro.  
  
```  
BOOL IsOnLastRecord();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o registro atual é o último registro no conjunto de registros; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é útil para escrever suas próprias implementações do padrão manipuladores de atualização de comando que grava ClassWizard para oferecer suporte a uma interface do usuário para mover de um registro para outro.  
  
> [!CAUTION]
>  O resultado dessa função é confiável, exceto que o modo de exibição não pode detectar o fim do conjunto de registros até que o usuário ter sido movido após ele. O usuário deve mover além do último registro antes da exibição de registro pode dizer que ele desative quaisquer objetos de interface do usuário para mover para o próximo ou o último registro. Se o usuário ultrapassar o último registro e, em seguida, volte para o último registro (ou anterior), a exibição do registro pode rastrear a posição do usuário no conjunto de registros e desativar objetos de interface de usuário corretamente. `IsOnLastRecord`também é confiável após uma chamada para a função de implementação **OnRecordLast**, que trata o `ID_RECORD_LAST` comando, ou `CRecordset::MoveLast`.  
  
##  <a name="ongetrecordset"></a>CRecordView::OnGetRecordset  
 Retorna um ponteiro para o `CRecordset`-derivados do objeto associado com a exibição do registro.  
  
```  
virtual CRecordset* OnGetRecordset() = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CRecordset`-objeto derivado se o objeto foi com êxito criado; caso contrário, uma **nulo** ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Você deve substituir essa função de membro para construir ou obter um objeto recordset e retornar um ponteiro para ele. Se você declarar a classe de exibição de registro com ClassWizard, o assistente grava uma substituição padrão para você. Implementação do padrão do ClassWizard retorna o ponteiro de conjunto de registros armazenado na exibição do registro, se houver. Se não, ele constrói um objeto de conjunto de registros do tipo especificado com ClassWizard e chama seu **abrir** membro de função para abrir a tabela ou executar a consulta e, em seguida, retorna um ponteiro para o objeto.  
  
 Para obter mais informações e exemplos, consulte o artigo [exibições de registro: usando uma exibição de registro](../../data/using-a-record-view-mfc-data-access.md).  
  
##  <a name="onmove"></a>CRecordView::OnMove  
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
 A implementação padrão chama apropriado **mover** função de membro de `CRecordset` objeto associado com a exibição do registro.  
  
 Por padrão, `OnMove` atualiza o registro atual na fonte de dados se o usuário alterou na exibição do registro.  
  
 O Assistente para aplicativo cria um recurso de menu com itens de menu do primeiro registro, último registro, próximo registro e registro anterior. Se você selecionar a opção ferramentas acoplável, o Assistente de aplicativo também cria uma barra de ferramentas com botões correspondentes a esses comandos.  
  
 Se você mover além do último registro no conjunto de registros, o modo de exibição de registro continua a exibir o último registro. Se você voltar após o primeiro registro, o modo de exibição de registro continua a exibir o primeiro registro.  
  
> [!CAUTION]
>  Chamando `OnMove` lança uma exceção se o conjunto de registros não contém registros. Chamar a função de manipulador de atualização do usuário apropriada interface — **OnUpdateRecordFirst**, **OnUpdateRecordLast**, **OnUpdateRecordNext**, ou **OnUpdateRecordPrev** — correspondente antes de mover a operação para determinar se o conjunto de registros tem todos os registros.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFormView](../../mfc/reference/cformview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRecordset](../../mfc/reference/crecordset-class.md)   
 [Classe CFormView](../../mfc/reference/cformview-class.md)

