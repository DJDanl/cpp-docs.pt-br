---
title: _inp, _inpw, _inpd | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _inp
- _inpw
- _inpd
apilocation:
- msvcrt.dll
- msvcr120.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr80.dll
- msvcr100.dll
- msvcr90.dll
apitype: DLLExport
f1_keywords:
- inpd
- _inp
- _inpw
- _inpd
dev_langs: C++
helpviewer_keywords:
- inp function
- inpw function
- ports, I/O routines
- inpd function
- _inp function
- _inpd function
- I/O [CRT], port
- _inpw function
ms.assetid: 5d9c2e38-fc85-4294-86d5-7282cc02d1b3
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 15fa7169f46e84cf60e1b869e5eb68a392b16a3a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="inp-inpw-inpd"></a>_inp, _inpw, _inpd
Entradas, de uma porta, um byte (`_inp`), uma palavra (`_inpw`) ou uma palavra dupla (`_inpd`).  
  
> [!IMPORTANT]
>  Essas funções estão obsoletas. A partir do Visual Studio 2015, elas não estão disponíveis no CRT.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _inp(   
   unsigned short port   
);  
unsigned short _inpw(   
   unsigned short port   
);  
unsigned long _inpd(   
   unsigned short port   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `port`  
 Número da porta de E/S.  
  
## <a name="return-value"></a>Valor retornado  
 As funções retornam o byte, a palavra, ou as palavras duplas lidas de `port`. Nenhum erro é retornado.  
  
## <a name="remarks"></a>Comentários  
 As funções `_inp`, `_inpw` e `_inpd` leem um byte, uma palavra e uma palavra dupla, respectivamente, da porta de entrada especificada. O valor de entrada pode ser qualquer inteiro curto sem sinal no intervalo de 0 a 65.535.  
  
 Como são lidas diretamente de uma porta de E/S, essas funções podem não ser usadas no código do usuário no Windows NT, Windows 2000, Windows XP e Windows Server 2003.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_inp`|\<conio.h>|  
|`_inpw`|\<conio.h>|  
|`_inpd`|\<conio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [E/S de porta e console](../c-runtime-library/console-and-port-i-o.md)   
 [_outp, _outpw, _outpd](../c-runtime-library/outp-outpw-outpd.md)