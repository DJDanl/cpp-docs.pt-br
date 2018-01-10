---
title: "-kernel (criar Kernel modo binário) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /kernel
- /kernel-
dev_langs: C++
ms.assetid: 6d7fdff0-c3d1-4b78-9367-4da588ce8b05
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b0e20df59788577acb680cbd18b737f7ec2d7822
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="kernel-create-kernel-mode-binary"></a>/kernel (criar binário do modo kernel)
Cria um binário que pode ser executado no kernel do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/kernel[-]  
```  
  
## <a name="arguments"></a>Arguments  
 **/kernel**  
 O código no projeto atual é compilado e vinculado usando um conjunto de regras da linguagem C++ que são específicos para o código que será executado no modo de kernel.  
  
 **/kernel-**  
 O código no projeto atual é compilado e vinculado sem usar as regras de linguagem C++ que são específicas para o código que será executado no modo de kernel.  
  
## <a name="remarks"></a>Comentários  
 Não há nenhum `#pragma` equivalente para controlar essa opção.  
  
 Especificando o **/kernel** opção informa ao compilador e vinculador para decidir quais recursos de linguagem são permitidos no modo kernel e certificar-se de que haja energia expressiva suficiente para evitar instabilidade no tempo de execução que é exclusivo para o modo de kernel C++. Isso é feito, proibindo o uso de recursos de linguagem C++ que causam interrupções no modo kernel e fornecendo avisos para recursos de linguagem C++ que são potencialmente interrupções, mas não podem ser desabilitados.  
  
 O **/kernel** opção se aplica ao compilador e vinculador fases de uma compilação e é definida no nível de projeto. Passar o **/kernel** switch para indicar ao compilador que o binário resultante, depois de vincular, deve ser carregado no kernel do Windows. O compilador restringirá a gama de recursos de linguagem do C++ a um subconjunto que é compatível com o kernel.  
  
 A tabela a seguir lista as alterações no comportamento do compilador quando **/kernel** for especificado.  
  
|Tipo de comportamento|**/kernel** comportamento|  
|-------------------|---------------------------|  
|Tratamento de exceções C++|Desabilitado. Todas as instâncias de `throw` e `try` palavras-chave emitir um erro do compilador (exceto para a especificação de exceção `throw()`). Não **/EH** opções são compatíveis com **/kernel**, exceto para **/EH-**.|  
|RTTI|Desabilitado. Todas as instâncias de `dynamic_cast` e `typeid` palavras-chave para emitir um erro do compilador, a menos que `dynamic_cast` usado estaticamente.|  
|`new` e `delete`|Você deve definir explicitamente o `new()` ou `delete()` operador; o compilador nem o tempo de execução fornecerá uma definição default.|  
  
 Personalizada chamada convenções, o [/GS](../../build/reference/gs-buffer-security-check.md) opção de compilação e todas as otimizações são permitidas quando você usar o **/kernel** opção. Inlining em grande parte não é afetada por **/kernel**, com a mesma semântica cumprida pelo compilador. Se você quiser garantir que o `__forceinline` inlining qualificador é cumprido, você deve garantir que o aviso [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) está habilitado para que você saiba quando um determinado `__forceinline` não é função embutida.  
  
 Quando o compilador é passado a **/kernel** comutador, ele predefine uma macro de pré-processador chamado `_KERNEL_MODE` e tem o valor **1**. Você pode usar isso para compilar condicionalmente com base em se o ambiente de execução no modo de usuário ou modo de kernel do código. Por exemplo, o código a seguir especifica que a classe deve estar em um segmento de memória não paginável quando ele é compilado para execução em modo kernel.  
  
```cpp  
#ifdef _KERNEL_MODE  
#define NONPAGESECTION __declspec(code_seg("$kerneltext$"))  
#else  
#define NONPAGESECTION  
#endif  
  
class NONPAGESECTION MyNonPagedClass  
{  
   // ...
};  
```  
  
 Alguns seguintes combinações de arquitetura de destino e o **/arch** opção produzirá um erro quando eles são usados com **/kernel**:  
  
-   **/arch: {SSE &#124; SSE2 &#124; AVX}** não têm suporte em x86. Somente **/arch:IA32** é compatível com **/kernel** em x86.  
  
-   **/arch: avx** não é compatível com **/kernel** em x64.  
  
 Compilando com **/kernel** também passa **/kernel** ao vinculador. Ela é como isso afeta o comportamento do vinculador:  
  
-   Vínculo incremental está desabilitado. Se você adicionar **/incremental** à linha de comando, o vinculador emite o erro fatal:  
  
     **LINK: erro fatal LNK1295: '/ INCREMENTAL' não é compatível com ' / KERNEL' especificação; link sem '/incremental'**  
  
-   Verifica se o vinculador de cada arquivo de objeto (ou qualquer membro incluído arquivamento de bibliotecas estáticas) para ver se ele foi foram compilado usando o **/kernel** opção mas não foi. Se todas as instâncias atendem esse critério, o vinculador links ainda com êxito mas pode emitir um aviso, conforme mostrado na tabela a seguir.  
  
    ||**/kernel** obj|**/kernel-** obj, MASM obj, ou cvtresed|Uma combinação de **/kernel** e **/kernel-** objs|  
    |-|----------------------|-----------------------------------------------|-------------------------------------------------|  
    |**link /kernel**|Sim|Sim|Sim, com o aviso LNK4257|  
    |**link**|Sim|Sim|Sim|  
  
     **Objeto de vinculação LNK4257 não compilado com /KERNEL; imagem não pode ser executada**  
  
 O **/kernel** opção e o **/driver** opção operar de forma independente e não afeta a outra.  
  
### <a name="to-set-the-kernel-compiler-option-in-visual-studio"></a>Para definir a opção de compilador /kernel no Visual Studio  
  
1.  Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  No **opções adicionais** caixa, adicione `/kernel` ou `/kernel-`.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)