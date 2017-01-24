---
title: "Classe de CRegKey | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CRegKey"
  - "ATL::CRegKey"
  - "ATL.CRegKey"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, registro"
  - "Classe de CRegKey"
  - "registro, excluindo chaves"
  - "registro, excluindo valores"
  - "registro, gravação"
ms.assetid: 3afce82b-ba2c-4c1a-8404-dc969e1af74b
caps.latest.revision: 25
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CRegKey
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para manipular as entradas no Registro do sistema.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CRegKey  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRegKey::CRegKey](../Topic/CRegKey::CRegKey.md)|o construtor.|  
|[CRegKey::~CRegKey](../Topic/CRegKey::~CRegKey.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRegKey::Attach](../Topic/CRegKey::Attach.md)|Chamar esse método para anexar um HKEY ao objeto de `CRegKey` definindo a alça de membro de [m\_hKey](../Topic/CRegKey::m_hKey.md) a `hKey`.|  
|[CRegKey::Close](../Topic/CRegKey::Close.md)|Chamar este método para liberar a alça de membro de [m\_hKey](../Topic/CRegKey::m_hKey.md) e para defini\-la PARA ANULAR.|  
|[CRegKey::Create](../Topic/CRegKey::Create.md)|Chamar esse método para criar a chave especificada, se não existir como uma subchave de `hKeyParent`.|  
|[CRegKey::DeleteSubKey](../Topic/CRegKey::DeleteSubKey.md)|Chamar esse método para remover a chave de Registro especificada.|  
|[CRegKey::DeleteValue](../Topic/CRegKey::DeleteValue.md)|Chamar esse método para remover um campo de valor de [m\_hKey](../Topic/CRegKey::m_hKey.md).|  
|[CRegKey::Detach](../Topic/CRegKey::Detach.md)|Chamar esse método para desanexe a alça de membro de [m\_hKey](../Topic/CRegKey::m_hKey.md) do objeto de `CRegKey` e set. `m_hKey` ao NULL|  
|[CRegKey::EnumKey](../Topic/CRegKey::EnumKey.md)|Chamar esse método para enumerar as subchaves da chave do Registro aberta.|  
|[CRegKey::Flush](../Topic/CRegKey::Flush.md)|Chamar esse método para gravar todos os atributos de chave do Registro aberta no Registro.|  
|[CRegKey::GetKeySecurity](../Topic/CRegKey::GetKeySecurity.md)|Chamar esse método para recuperar uma cópia do descritor de segurança que protege a chave do Registro aberta.|  
|[CRegKey::NotifyChangeKeyValue](../Topic/CRegKey::NotifyChangeKeyValue.md)|Este método notifica o chamador sobre alterações aos atributos ou ao conteúdo da chave do Registro aberta.|  
|[CRegKey::Open](../Topic/CRegKey::Open.md)|Chamar esse método para abrir a chave especificada e [m\_hKey](../Topic/CRegKey::m_hKey.md) ajustado para o identificador de essa chave.|  
|[CRegKey::QueryBinaryValue](../Topic/CRegKey::QueryBinaryValue.md)|Chamar esse método para recuperar os dados binários para um nome especificado de valor.|  
|[CRegKey::QueryDWORDValue](../Topic/CRegKey::QueryDWORDValue.md)|Chamar esse método para recuperar os dados DWORD para um nome especificado de valor.|  
|[CRegKey::QueryGUIDValue](../Topic/CRegKey::QueryGUIDValue.md)|Chamar esse método para recuperar dados de GUID para um nome especificado de valor.|  
|[CRegKey::QueryMultiStringValue](../Topic/CRegKey::QueryMultiStringValue.md)|Chamar esse método para recuperar os dados multistring para um nome especificado de valor.|  
|[CRegKey::QueryQWORDValue](../Topic/CRegKey::QueryQWORDValue.md)|Chamar esse método para recuperar dados de QWORD para um nome especificado de valor.|  
|[CRegKey::QueryStringValue](../Topic/CRegKey::QueryStringValue.md)|Chamar esse método para recuperar dados da cadeia de caracteres para um nome especificado de valor.|  
|[CRegKey::QueryValue](../Topic/CRegKey::QueryValue.md)|Chamar esse método para recuperar os dados para o campo de valor especificado de [m\_hKey](../Topic/CRegKey::m_hKey.md).  As versões anteriores de este método não são suportadas e marcadas como **ATL\_DEPRECATED**.|  
|[CRegKey::RecurseDeleteKey](../Topic/CRegKey::RecurseDeleteKey.md)|Chamar esse método para remover a chave de Registro especificada e remover explicitamente todas as subchaves.|  
|[CRegKey::SetBinaryValue](../Topic/CRegKey::SetBinaryValue.md)|Chamar esse método para definir o valor binário da chave do Registro.|  
|[CRegKey::SetDWORDValue](../Topic/CRegKey::SetDWORDValue.md)|Chamar esse método para definir o valor DWORD da chave do Registro.|  
|[CRegKey::SetGUIDValue](../Topic/CRegKey::SetGUIDValue.md)|Chamar esse método para definir o valor GUID da chave do Registro.|  
|[CRegKey::SetKeySecurity](../Topic/CRegKey::SetKeySecurity.md)|Chamar esse método para definir a segurança da chave do Registro.|  
|[CRegKey::SetKeyValue](../Topic/CRegKey::SetKeyValue.md)|Chamar esse método para armazenar dados no campo especificado o valor de uma chave especificada.|  
|[CRegKey::SetMultiStringValue](../Topic/CRegKey::SetMultiStringValue.md)|Chamar esse método para definir o valor multistring da chave do Registro.|  
|[CRegKey::SetQWORDValue](../Topic/CRegKey::SetQWORDValue.md)|Chamar esse método para definir o valor de QWORD da chave do Registro.|  
|[CRegKey::SetStringValue](../Topic/CRegKey::SetStringValue.md)|Chamar esse método para definir o valor da cadeia de caracteres de chave do Registro.|  
|[CRegKey::SetValue](../Topic/CRegKey::SetValue.md)|Chamar esse método para armazenar dados em um campo de valor especificado de [m\_hKey](../Topic/CRegKey::m_hKey.md).  As versões anteriores de este método não são suportadas e marcadas como **ATL\_DEPRECATED**.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRegKey::operator HKEY](../Topic/CRegKey::operator%20HKEY.md)|Converte um objeto de `CRegKey` a um HKEY.|  
|[CRegKey::operator \=](../Topic/CRegKey::operator%20=.md)|Operador de atribuição.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRegKey::m\_hKey](../Topic/CRegKey::m_hKey.md)|Contém um identificador de chave do Registro associado com o objeto de `CRegKey` .|  
|[CRegKey::m\_pTM](../Topic/CRegKey::m_pTM.md)|Ponteiro para o objeto de `CAtlTransactionManager`|  
  
## Comentários  
 `CRegKey` fornece métodos para criar e excluir chaves e valores no Registro do sistema.  O Registro contém um conjunto instalação\- específico de definições para componentes do sistema, como números de versão de software, mapeamentos de lógico\-à\- discussão de hardware instalado, e objetos COM.  
  
 `CRegKey` fornece uma interface de programação do Registro do sistema para um determinado computador.  Por exemplo, para abrir uma chave do Registro específica, chame `CRegKey::Open`.  Para recuperar ou modificar um valor de dados, uma chamada `CRegKey::QueryValue` ou um `CRegKey::SetValue`, respectivamente.  Para fechar uma chave, chame `CRegKey::Close`.  
  
 Quando você fechar uma chave do Registro, os dados são gravados \(solto\) no disco rígido.  Esse processo pode levar alguns segundos.  Se seu aplicativo deve explicitamente gravar dados de Registro no disco rígido, você pode chamar a função de [RegFlushKey](http://msdn.microsoft.com/library/windows/desktop/ms724867) Win32.  Em o entanto, **RegFlushKey** usa vários recursos do sistema e deve ser chamado somente quando necessário absolutamente.  
  
> [!IMPORTANT]
>  Todos os métodos que permitem que o chamador especificar um local de Registro têm o potencial lê os dados que não podem ser confiáveis.  Os métodos que utilizam [RegQueryValueEx](http://msdn.microsoft.com/library/windows/desktop/ms724911) devem levar em consideração que essa função não trata explicitamente as cadeias de caracteres que são terminadas NULAS.  Ambas as condições devem ser marcadas para o código de chamada.  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Exemplo do DCOM](../../top/visual-cpp-samples.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Registry Overview](http://msdn.microsoft.com/library/windows/desktop/ms724871)   
 [Registry Functions](http://msdn.microsoft.com/library/windows/desktop/ms724875)   
 [Registry Value Types](http://msdn.microsoft.com/library/windows/desktop/ms724884)