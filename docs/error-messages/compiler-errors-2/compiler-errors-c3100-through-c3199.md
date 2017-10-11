---
title: C3100 de erros do compilador por meio de C3199 | Microsoft Docs
ms.custom: 
ms.date: 04/21/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3102
- C3105
- C3107
- C3108
- C3109
- C3111
- C3112
- C3119
- C3122
- C3123
- C3124
- C3125
- C3127
- C3128
- C3129
- C3143
- C3144
- C3146
- C3147
- C3148
- C3151
- C3158
- C3164
- C3165
- C3169
- C3177
- C3178
- C3184
- C3188
- C3191
- C3193
helpviewer_keywords:
- C3102
- C3105
- C3107
- C3108
- C3109
- C3111
- C3112
- C3119
- C3122
- C3123
- C3124
- C3125
- C3127
- C3128
- C3129
- C3143
- C3144
- C3146
- C3147
- C3148
- C3151
- C3158
- C3164
- C3165
- C3169
- C3177
- C3178
- C3184
- C3188
- C3191
- C3193
dev_langs:
- C++
ms.assetid: 7bc40c2f-6a8d-488a-b665-f39375afee77
caps.latest.revision: 1
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 7060d03845cf81aeaedc5eff48db3aec59716112
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-errors-c3100-through-c3199"></a>C3100 de erros do compilador por meio de C3199
Os artigos nesta parte da documentação contêm informações sobre uma subseção de erros do compilador do Visual C++. Você pode acessar as informações aqui ou no **saída** janela no Visual Studio, você pode selecionar um número de erro e, em seguida, escolha a tecla F1.  
  
> [!NOTE]
>  Nem todo [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] erro está documentado no MSDN. Em muitos casos, a mensagem de diagnóstica fornece todas as informações que estão disponíveis. Se você achar que precisa de uma mensagem de erro explicação adicional, você poderá nos informar. Use o formulário de comentários nesta página, ou vá para a barra de menus do Visual Studio e escolha **ajuda**, **relatar um erro**, ou você pode enviar um relatório de sugestão ou um bug no [Microsoft Connect](http://connect.microsoft.com/VisualStudio).  
  
 Você pode obter assistência adicional para erros e avisos nos fóruns públicos do MSDN. O [linguagem Visual C++](http://go.microsoft.com/fwlink/?LinkId=158195) fórum é para perguntas e discussões sobre o [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] sintaxe de linguagem e compilador. O [geral do Visual C++](http://go.microsoft.com/fwlink/?LinkId=158194) fórum é para perguntas sobre [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] que não são abordados em outros fóruns. Você também pode encontrar ajuda sobre erros e avisos sobre [estouro de pilha](http://stackoverflow.com/).  
  
|Erro|Mensagem|  
|-----------|-------------|  
|[Erro do compilador C3100](compiler-error-c3100.md)|'*identificador*': qualificador de atributo desconhecido|  
|[Erro do compilador C3101](compiler-error-c3101.md)|expressão inválida para argumento de atributo nomeado '*identificador*'|  
|C3102 de erro do compilador|Obsoleto.|  
|[Erro do compilador C3103](compiler-error-c3103.md)|'*identificador*': argumento nomeado repetido|  
|[Erro do compilador C3104](compiler-error-c3104.md)|argumento de atributo inválido|  
|C3105 de erro do compilador|'*símbolo*': não pode ser usado como um atributo|  
|[Erro do compilador C3106](compiler-error-c3106.md)|'*atributo*': argumentos sem nome devem preceder argumentos nomeados|  
|C3107 de erro do compilador|'*atributo*': funções de membro de atributos nativos não podem ser definidas|  
|C3108 de erro do compilador|não é possível deduzir um tipo como uma lista de inicializadores não é uma expressão|  
|C3109 de erro do compilador|'*identificador*': métodos de interface devem usar o stdcall' ou cdecl' convenção de chamada|  
|[Erro do compilador C3110](compiler-error-c3110.md)|'*função*': não é possível sobrecarregar um método de interface COM|  
|C3111 de erro do compilador|Uma lista de inicializadores não pode ser usada como argumento para um parâmetro de modelo padrão|  
|C3112 de erro do compilador|'*interface*': uma interface só pode ser declarada em global ou escopo de namespace|  
|[Erro do compilador C3113](compiler-error-c3113.md)|um 'interface/enum' não pode ser um modelo/generic|  
|[Erro do compilador C3114](compiler-error-c3114.md)|'*identificador*': argumento de atributo nomeado não válido|  
|[Erro do compilador C3115](compiler-error-c3115.md)|'*atributo*': este atributo não é permitido em '*construir*'|  
|[Erro do compilador C3116](compiler-error-c3116.md)|'*especificador*': classe de armazenamento inválida para método de interface|  
|[Erro do compilador C3117](compiler-error-c3117.md)|'*interface*': uma interface só pode ter uma classe base|  
|[Erro do compilador C3118](compiler-error-c3118.md)|'*interface*': interfaces não suportam herança virtual|  
|C3119 de erro do compilador|alignas(void) não é permitido|  
|[Erro do compilador C3120](compiler-error-c3120.md)|'*identificador*': métodos de interface não podem levar a uma lista de argumentos variáveis|  
|[Erro do compilador C3121](compiler-error-c3121.md)|não é possível alterar o GUID para classe*classe*'|  
|C3122 de erro do compilador|'*interface*': uma interface genérica WinRT não pode ter um GUID|  
|C3123 de erro do compilador|Interface genérica WinRT não pode ter restrições|  
|C3124 de erro do compilador|'signed char' não é um tipo de dados válido do WinRT. Em vez disso, use 'unsigned char', 'wchar_t' ou 'signed short'.|  
|C3125 de erro do compilador|'*tipo*': tipo não pode derivar direta ou indiretamente de 'Platform:: Exception'|  
|[Erro do compilador C3126](compiler-error-c3126.md)|não é possível definir uma união '*união*'dentro de tipo gerenciado/WinRT'*tipo*'|  
|C3127 de erro do compilador|'*tipo*': '*característica*' característica só pode ser usada em uma classe de ref WinRT|  
|C3128 de erro do compilador|'*tipo*'não tem uma vtable introduzida por'*tipo*'|  
|C3129 de erro do compilador|'*tipo*': default_vptr_for_base só pode ser usado em bases e tipos polimórficos definidos localmente|  
|[Erro do compilador C3130](compiler-error-c3130.md)|Erro do compilador interno: Falha ao gravar bloco de código injetado em PDB|  
|[Erro do compilador C3131](compiler-error-c3131.md)|projeto deve ter um atributo 'module' com a propriedade 'name'|  
|[Erro do compilador C3132](compiler-error-c3132.md)|'*parâmetro*': matrizes de parâmetro só podem ser aplicados a um argumento formal do tipo 'matriz unidimensional de gerenciados/WinRT'|  
|[Erro do compilador C3133](compiler-error-c3133.md)|Atributos não podem ser aplicados a C++ varargs|  
|[Erro do compilador C3134](compiler-error-c3134.md)|'*valor*': valor do argumento de atributo '*argumento*'não tem tipo válido'*tipo*'|  
|[Erro do compilador C3135](compiler-error-c3135.md)|'*identificador*': uma propriedade não pode ter uma 'const' ou 'volatile' de tipo|  
|[Erro do compilador C3136](compiler-error-c3136.md)|'*interface*': uma interface COM só pode herdar de outra interface COM '*interface*' não é uma interface COM|  
|[Erro do compilador C3137](compiler-error-c3137.md)|'*identificador*': uma propriedade não pode ser inicializada|  
|[Erro do compilador C3138](compiler-error-c3138.md)|'*identificador*': um '*atributo*' interface deve herdar de IDispatch, ou de uma interface que herde de IDispatch|  
|[Erro do compilador C3139](compiler-error-c3139.md)|'*tipo*': não é possível exportar um UDT sem membros|  
|[Erro do compilador C3140](compiler-error-c3140.md)|não é possível ter vários atributos de 'module' na mesma unidade de compilação|  
|[Erro do compilador C3141](compiler-error-c3141.md)|'*interface*': interfaces suportam apenas herança public|  
|[Erro do compilador C3142](compiler-error-c3142.md)|'*propriedade*': não é possível definir o endereço de uma propriedade|  
|C3143 de erro do compilador|'*argumento*': argumento de atributo não pode ter vários valores|  
|C3144 de erro do compilador|'*atributo*': atributo requer argumentos explícitos, '*argumento*' está sem nome|  
|[Erro do compilador C3145](compiler-error-c3145.md)|'*identificador*': variável global ou estática pode não ter tipo gerenciado/WinRT '*tipo*'|  
|C3146 de erro do compilador|Obsoleto.|  
|C3147 de erro do compilador|Obsoleto.|  
|C3148 de erro do compilador|Obsoleto.|  
|[Erro do compilador C3149](compiler-error-c3149.md)|'*tipo*': não é possível usar este tipo aqui sem um nível superior '*token*'|  
|[Erro do compilador C3150](compiler-error-c3150.md)|'*construir*': '*atributo*' só pode ser aplicado a uma classe, struct, interface, array ou ponteiro|  
|C3151 de erro do compilador|Obsoleto.|  
|[Erro do compilador C3152](compiler-error-c3152.md)|'*função*': '*palavra-chave*' só pode ser aplicado a uma classe, struct ou função membro virtual|  
|[Erro do compilador C3153](compiler-error-c3153.md)|'*interface*': não é possível criar uma instância de uma interface|  
|[Erro do compilador C3154](compiler-error-c3154.md)|Esperado ',' antes de reticências. Vírgula não separados não tem suportada em funções de matriz de parâmetro de reticências.|  
|[Erro do compilador C3155](compiler-error-c3155.md)|atributos não são permitidos em um indexador de propriedades|  
|[Erro do compilador C3156](compiler-error-c3156.md)|'*classe*': você não pode ter uma definição de local de um tipo gerenciado/WinRT|  
|[Erro do compilador C3157](compiler-error-c3157.md)|Atributo ParamArray só pode ser aplicado ao último parâmetro|  
|C3158 de erro do compilador|'*função*': '*palavra-chave*' só pode ser aplicado a uma função membro virtual|  
|[Erro do compilador C3159](compiler-error-c3159.md)|'*identificador*': matriz de ponteiros para tipo de valor não pode ser declarado|  
|[Erro do compilador C3160](compiler-error-c3160.md)|'*tipo*': um membro de dados de uma classe gerenciada/WinRT não pode ter esse tipo|  
|[Erro do compilador C3161](compiler-error-c3161.md)|'*interface*': aninhamento class, struct ou interface em uma interface é inválido; aninhar interface em class ou struct é inválido|  
|[Erro do compilador C3162](compiler-error-c3162.md)|'*tipo*': um tipo de referência que tenha um destruidor não pode ser usado como o tipo de membro de dados estáticos '*membro*'|  
|[Erro do compilador C3163](compiler-error-c3163.md)|'*classe*': atributos inconsistentes com declaração anterior|  
|C3164 de erro do compilador|Obsoleto.|  
|C3165 de erro do compilador|'*valor*': não é possível converter um valor integral ou de ponto flutuante|  
|[Erro do compilador C3166](compiler-error-c3166.md)|Obsoleto. '*tipo*': um membro de dados de uma classe gerenciada/WinRT não pode ter tipo '*pointer_type* para interior *managed_pointer_type*'|  
|[Erro do compilador C3167](compiler-error-c3167.md)|Não foi possível inicializar o .NET Framework: Verifique se ele está instalado|  
|[Erro do compilador C3168](compiler-error-c3168.md)|'*tipo*': tipo subjacente inválido para enum|  
|C3169 de erro do compilador|'*tipo*': não é possível deduzir o tipo para 'auto' de '*tipo*'|  
|[Erro do compilador C3170](compiler-error-c3170.md)|não é possível ter identificadores de módulo diferentes em um projeto|  
|[Erro do compilador C3171](compiler-error-c3171.md)|'*módulo*': não é possível especificar atributos de módulo diferentes em um projeto|  
|[Erro do compilador C3172](compiler-error-c3172.md)|'*identificador*': não é possível especificar atributos de idl_module diferentes em um projeto|  
|[Erro do compilador C3173](compiler-error-c3173.md)|incompatibilidade de versão em mesclagem de idl|  
|[Erro do compilador C3174](compiler-error-c3174.md)|atributo de módulo não foi especificado.|  
|[Erro do compilador C3175](compiler-error-c3175.md)|'*função*': não é possível chamar um método de um tipo gerenciado de função não gerenciada '*função*'|  
|[Erro do compilador C3176](compiler-error-c3176.md)|'*tipo*': não é possível declarar tipo value local|  
|C3177 de erro do compilador|Você não pode ter uma função de conversão para um tipo que contém '*tipo*'|  
|C3178 de erro do compilador|'*tipo*': não é possível usar ParamArray em uma função com argumentos padrão|  
|[Erro do compilador C3179](compiler-error-c3179.md)|um tipo gerenciado/WinRT sem nome não é permitido|  
|[Erro do compilador C3180](compiler-error-c3180.md)|'*tipo*': nome excede o limite de metadados de '*número*' caracteres|  
|[Erro do compilador C3181](compiler-error-c3181.md)|'*tipo*': operando inválido para *operador*|  
|[Erro do compilador C3182](compiler-error-c3182.md)|'*tipo*': uma declaração de acesso ou declaração de using membro é ilegal dentro de um tipo gerenciado/WinRT|  
|[Erro do compilador C3183](compiler-error-c3183.md)|não é possível definir sem nome de classe, struct ou união dentro de tipo gerenciado/WinRT '*classe*'|  
|C3184 de erro do compilador|Obsoleto.|  
|[Erro do compilador C3185](compiler-error-c3185.md)|'typeid': usado em tipo gerenciado/WinRT '*tipo*', use '*operador*' em vez disso|  
|C3186 de erro do compilador|Obsoleto.|  
|[Erro do compilador C3187](compiler-error-c3187.md)|'*identificador*': só está disponível dentro do corpo de uma função|  
|C3188 de erro do compilador|Obsoleto.|  
|[Erro do compilador C3189](compiler-error-c3189.md)|' typeid <*declarador*>': esta sintaxe não é mais suportado, use::typeid em vez disso|  
|[Erro do compilador C3190](compiler-error-c3190.md)|'*declarador*'com os argumentos de modelo fornecido não é a instanciação explícita de nenhuma função de membro de'*tipo*'|  
|C3191 de erro do compilador|Obsoleto.|  
|[Erro do compilador C3192](compiler-error-c3192.md)|Erro de sintaxe: ' ^' não é um operador de prefixo (Você quis dizer ' *'?)|  
|C3193 de erro do compilador|'*construir*': requer ' / clr' ou ' / ZW' opção de linha de comando|  
|[Erro do compilador C3194](compiler-error-c3194.md)|'*tipo*': um tipo de valor não pode ter um operador de atribuição|  
|[Erro do compilador C3195](compiler-error-c3195.md)|'*palavra-chave*': é reservado e não pode ser usado como um membro de um tipo de valor ou classe ref. Operadores CLR/WinRT devem ser definidas usando a palavra-chave 'operator'|  
|[Erro do compilador C3196](compiler-error-c3196.md)|'*identificador*': usado mais de uma vez|  
|[Erro do compilador C3197](compiler-error-c3197.md)|'*palavra-chave*': só pode ser usado em definições|  
|[Erro do compilador C3198](compiler-error-c3198.md)|Uso inválido de pragmas de ponto flutuantes: pragma fenv_access opera apenas em modo preciso|  
|[Erro do compilador C3199](compiler-error-c3199.md)|Uso inválido de pragmas de ponto flutuantes: exceções não são suportadas em modo não preciso|  

