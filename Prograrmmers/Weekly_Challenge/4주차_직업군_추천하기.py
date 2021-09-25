def solution(table, languages, preference):
    
    job_list = []
    job_lang_score = []
    
    for jobs in table:
        job_languages = jobs.split(' ')
        job_list.append(job_languages[0])
        
        lang_score = {}
        language_length = len(job_languages[1:])
        for idx, language in enumerate(job_languages[1:]):            
            score = language_length - idx
            lang_score[language] = score
            
        job_lang_score.append(lang_score)

    
    prefer_lang_score = []
    
    for idx,lang_score in enumerate(job_lang_score):
        total_score = 0
        for lang_idx,lang in enumerate(languages):
            if lang in lang_score:
                total_score += lang_score[lang] * preference[lang_idx]
        
        prefer_lang_score.append(total_score)
        
    max_score = max(prefer_lang_score)
    
    max_score_jobs = []
    
    for idx,score in enumerate(prefer_lang_score):
        if score == max_score:
            max_score_jobs.append(job_list[idx])
    
    max_score_jobs.sort()
    answer = max_score_jobs[0]
    
    return answer


def solution2(table, languages, preference):
    
    jobs_total_score = []

    for job_prefer_langs in table:
        job_prefer_langs = job_prefer_langs.split(' ')
        job = job_prefer_langs[0]
        prefer_langs = job_prefer_langs[1:]

        lang_score = {}
        LANG_LENGTH = 5
        for idx, language in enumerate(prefer_langs):
            score = LANG_LENGTH - idx
            lang_score[language] = score

        total_score = 0
        for idx, language in enumerate(languages):
            if language in lang_score:
                total_score += lang_score[language] * preference[idx]
        
        jobs_total_score.append([total_score, job])

    SCORE = 0
    JOB = 1

    jobs_total_score.sort(key=lambda x: (-x[SCORE], x[JOB]))
    answer = jobs_total_score[SCORE][JOB]

    return answer

def solution3(table, languages, preference):
    
    jobs_score = []

    for t in table:
        job_pref_langs = t.split()
        job = job_pref_langs[0]

        score = 0
        for lang, pref in zip(languages, preference):
            if lang in job_pref_langs:
                score += (6 - job_pref_langs.index(lang)) * pref

        jobs_score.append([score, job])

    jobs_score.sort(key=lambda x: (-x[0], x[1]))
    answer = jobs_score[0][1]
    
    return answer


table = [["SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"],["SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"]]
languages = [["PYTHON", "C++", "SQL"],["JAVA", "JAVASCRIPT"]]
preference = [[7, 5, 5],[7, 5]]

for idx in range(2):
    answer = solution3(table[idx], languages[idx], preference[idx])
    print(answer)