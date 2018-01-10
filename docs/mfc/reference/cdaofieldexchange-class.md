---
title: Classe CDaoFieldExchange | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDaoFieldExchange
- AFXDAO/CDaoFieldExchange
- AFXDAO/CDaoFieldExchange::IsValidOperation
- AFXDAO/CDaoFieldExchange::SetFieldType
- AFXDAO/CDaoFieldExchange::m_nOperation
- AFXDAO/CDaoFieldExchange::m_prs
dev_langs: C++
helpviewer_keywords:
- CDaoFieldExchange [MFC], IsValidOperation
- CDaoFieldExchange [MFC], SetFieldType
- CDaoFieldExchange [MFC], m_nOperation
- CDaoFieldExchange [MFC], m_prs
ms.assetid: 350a663e-92ff-44ab-ad53-d94efa2e5823
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1c4a62d3f9631d4e2807bf12e1eda3bd4b4f5112
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdaofieldexchange-class"></a>Classe CDaoFieldExchange
Oferece suporte as rotinas de troca (DFX) dos campos de registro DAO usadas pelas classes de banco de dados DAO.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDaoFieldExchange  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoFieldExchange::IsValidOperation](#isvalidoperation)|Retorna zero se a operação atual for apropriado para o tipo de campo que está sendo atualizado.|  
|[CDaoFieldExchange::SetFieldType](#setfieldtype)|Especifica o tipo de membro de dados do conjunto de registros, coluna ou parâmetro — representado por todas as chamadas subsequentes para funções DFX até a próxima chamada para `SetFieldType`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoFieldExchange::m_nOperation](#m_noperation)|A operação de DFX que está sendo executada pela chamada atual para o conjunto de registros `DoFieldExchange` função de membro.|  
|[CDaoFieldExchange::m_prs](#m_prs)|Um ponteiro para o conjunto de registros no qual DFX operações estão sendo executadas.|  
  
## <a name="remarks"></a>Comentários  
 `CDaoFieldExchange`não tem uma classe base.  
  
 Use essa classe se você estiver escrevendo rotinas de troca de dados para tipos de dados personalizados. Caso contrário, você não use diretamente desta classe. DFX troca dados entre os membros de dados do campo de seu [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto e os campos correspondentes do registro atual na fonte de dados. DFX gerencia o exchange em ambas as direções da fonte de dados e à fonte de dados. Consulte [53 de observação técnica](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md) para obter informações sobre como escrever rotinas DFX personalizadas.  
  
> [!NOTE]
>  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO. Em geral, as classes do MFC com base em DAO são mais compatíveis com que as classes do MFC com base em ODBC. As classes com base em DAO podem acessar dados, inclusive por meio de drivers ODBC, por meio de seu próprio mecanismo de banco de dados. Eles também oferecem suporte a operações de Data Definition Language (DDL), como adicionar tabelas por meio de classes em vez de precisar chamar DAO por conta própria.  
  
> [!NOTE]
>  Troca de campos de registro DAO (DFX) é muito semelhante à troca de campos de registro (RFX) nas classes de banco de dados baseado em ODBC MFC ( `CDatabase`, `CRecordset`). Se você entender RFX, você achará DFX fácil de usar.  
  
 Um `CDaoFieldExchange` objeto fornece as informações de contexto necessário para DAO registrar troca de campos entrem em vigor. `CDaoFieldExchange`objetos dão suporte a um número de operações, incluindo parâmetros de associação e os membros de dados de campo e definir vários sinalizadores nos campos do registro atual. DFX operações são executadas em membros de dados de classe de conjunto de registros de tipos definidos pelo `enum` **FieldType** em `CDaoFieldExchange`. Possíveis **FieldType** os valores são:  
  
- **CDaoFieldExchange::outputColumn** para membros de dados do campo.  
  
- **CDaoFieldExchange::param** para membros de dados do parâmetro.  
  
 O [IsValidOperation](#isvalidoperation) função de membro é fornecida para escrever suas próprias rotinas DFX personalizadas. Você usará [SetFieldType](#setfieldtype) frequentemente em sua [CDaoRecordset::DoFieldExchange](../../mfc/reference/cdaorecordset-class.md#dofieldexchange) funções. Para obter detalhes sobre as funções globais DFX, consulte [funções de troca de campos do registro](../../mfc/reference/record-field-exchange-functions.md). Para obter informações sobre como escrever rotinas DFX personalizadas para seus próprios tipos de dados, consulte [53 de observação técnica](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CDaoFieldExchange`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
##  <a name="isvalidoperation"></a>CDaoFieldExchange::IsValidOperation  
 Se você gravar sua própria função DFX, chame `IsValidOperation` no início de sua função para determinar se a operação atual pode ser executada em um tipo de membro de dados de campo específico (um **CDaoFieldExchange::outputColumn** ou um **CDaoFieldExchange::param**).  
  
```  
BOOL IsValidOperation();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação atual é apropriada para o tipo de campo que está sendo atualizado.  
  
### <a name="remarks"></a>Comentários  
 Algumas das operações executadas pelo mecanismo de DFX se aplicam somente a um tipo de campo possíveis. Segue o modelo das funções DFX existentes.  
  
 Para obter informações adicionais sobre como escrever rotinas DFX personalizadas, consulte [53 de observação técnica](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md).  
  
##  <a name="m_noperation"></a>CDaoFieldExchange::m_nOperation  
 Identifica a operação a ser executada no [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) associado ao objeto de troca de campos do objeto.  
  
### <a name="remarks"></a>Comentários  
 O `CDaoFieldExchange` objeto fornece o contexto para um número de diferentes operações DFX no conjunto de registros.  
  
> [!NOTE]
>  O **PSEUDONULL** descrito em operações de MarkForAddNew e SetFieldNull abaixo é um valor usado para marcar campos nulos. O mecanismo de troca de campos de registro DAO (DFX) usa esse valor para determinar quais campos foram explicitamente marcados como Null. **PSEUDONULL** não é necessária para [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) e [COleCurrency](../../mfc/reference/colecurrency-class.md) campos.  
  
 Os valores possíveis de **m_nOperation** são:  
  
|Operação|Descrição|  
|---------------|-----------------|  
|**AddToParameterList**|Cria o **parâmetros** cláusula da instrução SQL.|  
|**AddToSelectList**|Cria o **selecione** cláusula da instrução SQL.|  
|**BindField**|Associa um campo no banco de dados para um local de memória em seu aplicativo.|  
|**BindParam**|Define os valores de parâmetro de consulta do conjunto de registros.|  
|**Correção**|Define o status de Null para um campo.|  
|**AllocCache**|Aloca o cache usado para verificar se há "sujos" campos do conjunto de registros.|  
|**StoreField**|Salva o registro atual no cache.|  
|**LoadField**|Restaura as variáveis de membro de dados armazenados em cache no conjunto de registros.|  
|**FreeCache**|Libera o cache usado para verificar se há "sujos" campos do conjunto de registros.|  
|`SetFieldNull`|Define o status do campo para Null e o valor para **PSEUDONULL**.|  
|**MarkForAddNew**|Marca os campos "sujos" se não **PSEUDONULL**.|  
|**MarkForEdit**|Marca os campos "sujos" se não corresponder o cache.|  
|**SetDirtyField**|Conjuntos de campo valores marcados como "sujos".|  
|**DumpField**|Despeja o conteúdo de um campo (somente debug).|  
|**MaxDFXOperation**|Usado para verificação de entrada.|  
  
##  <a name="m_prs"></a>CDaoFieldExchange::m_prs  
 Contém um ponteiro para o [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto associado a `CDaoFieldExchange` objeto.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setfieldtype"></a>CDaoFieldExchange::SetFieldType  
 Chamar `SetFieldType` no seu `CDaoRecordset` da classe `DoFieldExchange` substituir.  
  
```  
void SetFieldType(UINT nFieldType);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFieldType`  
 Um valor de **enum FieldType**, declarado em `CDaoFieldExchange`, que pode ser um dos seguintes:  
  
- **CDaoFieldExchange::outputColumn**  
  
- **CDaoFieldExchange::param**  
  
### <a name="remarks"></a>Comentários  
 Normalmente, ClassWizard grava essa chamada para você. Se você escrever sua própria função e estiver usando o Assistente para gravar seu `DoFieldExchange` função, adicione chamadas para sua própria função fora o mapa de campo. Se você não usar o assistente, não haverá um mapeamento de campos. A chamada precede chamadas a funções DFX, uma para cada membro de dados do campo de sua classe e identifica o tipo de campo como **CDaoFieldExchange::outputColumn**.  
  
 Se você parametrizar sua classe de conjunto de registros, você deve adicionar DFX chamadas para todos os membros de dados de parâmetro (fora de mapa de campo) e preceder essas chamadas com uma chamada para `SetFieldType`. Passe o valor **CDaoFieldExchange::param**. (Em vez disso, você pode usar um [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) e definir os valores de parâmetro.)  
  
 Em geral, cada grupo de chamadas de função DFX associados a membros de dados do campo ou membros de dados do parâmetro deve ser precedido por uma chamada para `SetFieldType`. O `nFieldType` parâmetro de cada `SetFieldType` chamada identifica o tipo dos membros de dados representado pelas chamadas de função DFX que seguem o `SetFieldType` chamar.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)
