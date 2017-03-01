---
title: raise | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- raise
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- Raise
dev_langs:
- C++
helpviewer_keywords:
- signals, sending to executing programs
- raise function
- signals
- programs [C++], sending signals to executing programs
ms.assetid: a3ccd3ad-f68f-4a7b-a005-c3ebfb217e8b
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: ff8b387b81487e0c39ba5018487a1b8045bd0574
ms.lasthandoff: 02/25/2017

---
# <a name="raise"></a>raise
Envia um sinal para o programa em execução.  
  
> [!NOTE]
>  Não use esse método para desligar um aplicativo [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)], exceto em cenários de teste ou depuração. As formas programáticas ou de interface do usuário de fechar um aplicativo [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] não são permitidas de acordo com a Seção 3.6 dos [Requisitos de certificação de aplicativos do Windows 8](http://go.microsoft.com/fwlink/?LinkId=262889). Para obter mais informações, consulte [Ciclo de vida do aplicativo (aplicativos da Windows Store)](http://go.microsoft.com/fwlink/?LinkId=262853).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      int raise(  
int sig   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *sig*  
 Sinal a ser gerado.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, **raise** retornará 0. Caso contrário, retornará um valor diferente de zero.  
  
## <a name="remarks"></a>Comentários  
 A função **raise** envia *sig* para o programa em execução. Se uma chamada anterior a **signal** tiver instalado uma função de manipulação de sinal para *sig*, **raise** executará essa função. Se nenhuma função de manipulador tiver sido instalada, a ação padrão associada com o valor de sinal *sig* será obtida da seguinte maneira.  
  
|Sinal|Significado|Padrão|  
|------------|-------------|-------------|  
|`SIGABRT`|Encerramento anormal|Termina o programa de chamada com código de saída 3|  
|`SIGFPE`|Erro de ponto flutuante|Encerra o programa de chamada|  
|`SIGILL`|Instrução ilegal|Encerra o programa de chamada|  
|`SIGINT`|Interrupção CTRL+C|Encerra o programa de chamada|  
|`SIGSEGV`|Acesso ao armazenamento inválido|Encerra o programa de chamada|  
|`SIGTERM`|Solicitação de término enviado para o programa|Ignora o sinal|  
  
 Se o argumento não for um sinal válido conforme especificado acima, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se o erro não for tratado, a função define `errno` como `EINVAL` e retorna um valor diferente de zero.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|**raise**|\<signal.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [signal](../../c-runtime-library/reference/signal.md)
