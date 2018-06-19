---
title: Classe de valor Platform | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Guid
dev_langs:
- C++
helpviewer_keywords:
- Platform::Guid Struct
ms.assetid: 25c0bfb2-7f93-44d8-bdf4-ef4fbac3424a
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c295138d6239ce516b4f322fb5fc479e2235a6be
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33089445"
---
# <a name="platformguid-value-class"></a>Platform::classe de valor Guid
Representa um tipo de [GUID](http://msdn.microsoft.com/library/windows/desktop/aa373931\(v=vs.85\).aspx) no sistema de tipos do Tempo de Execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
public value struct Guid  
```  
  
### <a name="members"></a>Membros  
 O Guid possui os métodos Equals(), GetHashCode() e ToString() derivados da [Platform::Object Class](../cppcx/platform-object-class.md)e o método GetTypeCode() derivado da [Platform::Type Class](../cppcx/platform-type-class.md). Guid também tem os seguintes membros:  
  
|Membro|Descrição|  
|------------|-----------------|  
|[Guid](#ctor)|Inicializa uma nova instância da estrutura Guid.|  
|[operator==](#operator-equality)|Operador de igualdade.|  
|[operator!=](#operator-not-equal)|Operador de diferença.|  
|[operator()](#operator-call)|Converte um Guid em GUID.|  
  
### <a name="remarks"></a>Comentários  
 Para ver um exemplo de como gerar um novo Platform::Guid, usando a função do Windows [CoCreateGuid](http://msdn.microsoft.com/library/windows/desktop/ms688568\(v=vs.85\).aspx), consulte [WinRT component: How to generate a GUID? (Componente WinRT: como gerar um GUID?)](http://blogs.msdn.com/b/eternalcoding/archive/2013/03/25/winrt-component-how-to-generate-a-guid.aspx)  
  
### <a name="requirements"></a>Requisitos  
 **Suporte mínimo de cliente:** Windows 8  
  
 **Suporte mínimo de servidor:** Windows Server 2012  
  
 **Namespace:** Platform  
  
 **Metadados:** platform.winmd  

 
## <a name="ctor"></a> GUID:: GUID construtores
Inicializa uma nova instância de uma estrutura Guid.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
  
    Guid(  
        unsigned int a,   
        unsigned short b,   
        unsigned short c,   
        unsigned char d,   
        unsigned char e,   
        unsigned char f,   
        unsigned char g,   
        unsigned char h,   
        unsigned char i,   
        unsigned char j,   
        unsigned char k  );  
  
    Guid(GUID m);  
  
    Guid(  
        unsigned int a,   
        unsigned short b,   
        unsigned short c,   
        Array<unsigned char>^ n );  
```  
  
### <a name="parameters"></a>Parâmetros  
 `a`  
 Os primeiros 4 bytes de GUID.  
  
 `b`  
 Os 2 bytes seguintes de GUID.  
  
 `c`  
 Os 2 bytes seguintes de GUID.  
  
 `d`  
 O byte seguinte de GUID.  
  
 `e`  
 O byte seguinte de GUID.  
  
 `f`  
 O byte seguinte de GUID.  
  
 `g`  
 O byte seguinte de GUID.  
  
 `h`  
 O byte seguinte de GUID.  
  
 `i`  
 O byte seguinte de GUID.  
  
 `j`  
 O byte seguinte de GUID.  
  
 `k`  
 O byte seguinte de GUID.  
  
 `m`  
 Um GUID como definido.  
  
 `n`  
 Os 8 bytes restantes de GUID.  
  

## <a name="operator-equality"></a> GUID::Operator operador = =
Compara dois guids.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
Platform::Guid::operator==  
```  
  
### <a name="return-value"></a>Valor de retorno  
 True se dois guids são iguais.

## <a name="operator-inequality"></a> GUID::Operator! = operador
Compara dois guids.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
Platform::Guid::operator!=  
```  
  
### <a name="return-value"></a>Valor de retorno  
 True se dois guids não são iguais.



## <a name="operator-call"></a> Operador GUID
Converte implicitamente um [estrutura de GUID](http://msdn.microsoft.com/library/windows/desktop/aa373931\(v=vs.85\).aspx)GUID para um Platform.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
Platform::Guid operator()  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma estrutura de GUID.  
  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)